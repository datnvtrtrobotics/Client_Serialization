/*
 * DataPackage.h
 *
 *  Created on: Aug 20, 2024
 *      Author: tdat
 */

#ifndef INC_DATAPACKAGE_H_
#define INC_DATAPACKAGE_H_

#include <stdint.h>

#define HEADER_SIZE 2
#define MAX_STRING_LEN 1024

typedef struct {
    uint16_t string_len;
    uint8_t string[MAX_STRING_LEN];
} hello_world_stream_data_s;
typedef enum {
 date_stream_data_id = 1,
 time_stream_data_id = 2,
 adc_stream_data_id = 3,
 hello_world_data_id = 4,
 button_state_data_id = 5,
 mcu_temperature_data_id = 6,
}messageID;

typedef struct {
    uint8_t header[HEADER_SIZE];    // Header (2 bytes)
    uint16_t timestamp;             // Timestamp (2 bytes)
    uint8_t msgID;                  // Message ID (1 byte)
    uint16_t dataLength;            // Data Length (2 bytes)
    uint8_t *data;                  // Data (variable length)
    uint16_t checksum;              // Checksum (2 bytes)
} DataPack;

void PackDateStreamData(DataPack *pack, uint8_t day, uint8_t month, uint16_t year);
void PackHourStreamData(DataPack *pack, uint8_t hour, uint8_t minute, uint8_t second);
void PackAdcStreamData(DataPack *pack, uint16_t adcValue);
void PackHelloWorldStream(DataPack *pack, const char *helloString);
void PackButtonStreamData(DataPack *pack, uint8_t button_id, uint8_t button_state);
void PackTempStreamData(DataPack *pack, uint16_t temperature);
#endif /* INC_DATAPACKAGE_H_ */
