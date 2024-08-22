/*
 * SensorData.c
 *
 *  Created on: Aug 20, 2024
 *      Author: tdat
 */
#include "SensorData.h"
#include "DataPackage.h"
#include "stm32f1xx_hal_gpio.h"
#include <stdio.h>
#include "ADC.h"

extern ADCDriver adcDriver;
DataPack pack;

void myButtonChangeCallback(button_state_data_s stateData) {
	PackButtonStreamData(&pack, stateData.button_id, stateData.button_state);
}
void myTempChangeCallback(uint16_t temperature) {
	PackTempStreamData(&pack, temperature);
}
void SensorDataInit(SensorData *sensorData) {
    sensorData->buttons[0].gpio.pin = GPIO_PIN_4;
    sensorData->buttons[1].gpio.pin = GPIO_PIN_5;
    sensorData->buttons[2].gpio.pin = GPIO_PIN_6;

	sensorData->ButtonChange = myButtonChangeCallback;
	sensorData->TempChange = myTempChangeCallback;
}
void SensorDataUpdate(SensorData *sensorData) {
    for (int i = 0; i < MAX_BUTTONS; i++) {
        if (ButtonHandle_eventOnChange(&sensorData->buttons[i])) {
            button_state_data_s stateData;
            stateData.button_id = sensorData->buttons[i].gpio.pin;
            stateData.button_state = sensorData->buttons[i].state;

            if (sensorData->ButtonChange) {
                sensorData->ButtonChange(stateData);  // Gọi callback với dữ liệu trạng thái nút
            }
        }
    }
    uint16_t newTemp = adc_getTemp(&adcDriver);
    if (newTemp != sensorData->temperature) {
        sensorData->temperature = newTemp;
        if (sensorData->TempChange) {
            sensorData->TempChange(newTemp);
        }
    }
}


