/*
 * main.c
 *
 *  Created on: Aug 19, 2024
 *      Author: tdat
 */

#include "DataStream.h"
#include "DataPackage.h"
#include "uart.h"
#include "SensorData.h"
#include "TimerTaskManagement.h"

void DataStreamLoop(void) {
    SensorData sensorData;
    SensorDataInit(&sensorData);

    InitTimerTasks();
    while (1) {
        SensorDataUpdate(&sensorData);
        uint16_t current_time = HAL_GetTick();

        int dataID = TimerTaskManagement_run(current_time);
        if (dataID != -1) {
            switch (dataID) {
                case date_stream_data_id:
                	PackDateStreamData();
                    break;
                case time_stream_data_id:
                	PackHourStreamData();
                    break;
                case adc_stream_data_id:
                	PackAdcStreamData();
                    break;
                case hello_world_data_id:
                    PackHelloWorldStream();
                    break;
                default:
                    break;
            }
        }

    }
}

