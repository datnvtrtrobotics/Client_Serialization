/*
 * DataPackage.c
 *
 *  Created on: Aug 20, 2024
 *      Author: tdat
 */

#include "DataPackage.h"
#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdlib.h>

uint16_t calculateChecksum(uint8_t *data, uint16_t length) {
    uint16_t crc = 0xFFFF;
    for (uint16_t i = 0; i < length; i++) {
        crc ^= (uint16_t)data[i]; // XOR byte vào CRC

        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x0001) {
                crc = (crc >> 1) ^ 0x8005; // Sử dụng đa thức CRC16
            } else {
                crc = crc >> 1;
            }
        }
    }
    return crc;
}
void header(DataPack *pack, uint8_t id, uint16_t data_length) {
    pack->header[0] = 0xDE;
    pack->header[1] = 0xAB;
    pack->msgID = id;
    pack->dataLength = data_length;
}
void calculateAndSetChecksum(DataPack *pack) {
    uint16_t checksum_input_size = HEADER_SIZE + sizeof(pack->timestamp) + sizeof(pack->msgID) + sizeof(pack->dataLength) + pack->dataLength;
    uint8_t *checksum_input = (uint8_t*)malloc(checksum_input_size);

    if (checksum_input == NULL) {
        return;
    }

    memcpy(checksum_input, pack->header, HEADER_SIZE);
    memcpy(checksum_input + HEADER_SIZE, &pack->timestamp, sizeof(pack->timestamp));
    memcpy(checksum_input + HEADER_SIZE + sizeof(pack->timestamp), &pack->msgID, sizeof(pack->msgID));
    memcpy(checksum_input + HEADER_SIZE + sizeof(pack->timestamp) + sizeof(pack->msgID), &pack->dataLength, sizeof(pack->dataLength));
    memcpy(checksum_input + HEADER_SIZE + sizeof(pack->timestamp) + sizeof(pack->msgID) + sizeof(pack->dataLength), pack->data, pack->dataLength);

    pack->checksum = calculateChecksum(checksum_input, checksum_input_size);

    free(checksum_input);
}
void PackDateStreamData(DataPack *pack, uint8_t day, uint8_t month, uint16_t year) {

    header(pack, date_stream_data_id, 3);  // ID=1, data_length=3 (day, month, year)

    pack->data = (uint8_t*)malloc(pack->dataLength);

    pack->data[0] = day;
    pack->data[1] = month;
    pack->data[2] = year & 0xFF;  // Chỉ lấy byte thấp của year (8-bit)

    pack->timestamp = HAL_GetTick();  // Lấy thời gian hiện tại

    calculateAndSetChecksum(pack);
}
void PackHourStreamData(DataPack *pack, uint8_t hour, uint8_t minute, uint8_t second) {

    header(pack, time_stream_data_id, 3);

    pack->data = (uint8_t*)malloc(pack->dataLength);

    pack->data[0] = hour;
    pack->data[1] = minute;
    pack->data[2] = second;

    pack->timestamp = HAL_GetTick();

    calculateAndSetChecksum(pack);
}
void PackAdcStreamData(DataPack *pack, uint16_t adcValue) {
	header(pack, adc_stream_data_id,  sizeof(adcValue));

    pack->timestamp = HAL_GetTick();  // Giả sử bạn đang dùng hàm HAL_GetTick() để lấy thời gian hiện tại

    pack->dataLength = sizeof(adcValue);
    pack->data = (uint8_t*)malloc(pack->dataLength);
    memcpy(pack->data, &adcValue, sizeof(adcValue));

    calculateAndSetChecksum(pack);
}
void PackHelloWorldStream(DataPack *pack, const char *helloString) {
    uint16_t string_len = strlen(helloString);
    if (string_len > 1024) {
        string_len = 1024;
    }
    header(pack, hello_world_data_id, sizeof(string_len) + string_len);

    pack->data = (uint8_t*)malloc(pack->dataLength);
    if (pack->data == NULL) {
        // Xử lý khi không đủ bộ nhớ
        return;
    }

    memcpy(pack->data, &string_len, sizeof(string_len));
    memcpy(pack->data + sizeof(string_len), helloString, string_len);
    pack->timestamp = HAL_GetTick();

    calculateAndSetChecksum(pack);
}
void PackButtonStreamData(DataPack *pack, uint8_t button_id, uint8_t button_state) {
    header(pack, button_state_data_id, 2); // ID gói dữ liệu và độ dài

    pack->data = (uint8_t*)malloc(pack->dataLength);
    pack->data[0] = button_id;
    pack->data[1] = button_state;

    pack->timestamp = HAL_GetTick();

    calculateAndSetChecksum(pack);
}
void PackTempStreamData(DataPack *pack, uint16_t temperature) {
    header(pack, mcu_temperature_data_id, sizeof(temperature));

    pack->data = (uint8_t*)malloc(pack->dataLength);
    memcpy(pack->data, &temperature, sizeof(temperature));

    pack->timestamp = HAL_GetTick();

    calculateAndSetChecksum(pack);
}
