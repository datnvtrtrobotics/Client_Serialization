/*
 * SensorData.h
 *
 *  Created on: Aug 20, 2024
 *      Author: tdat
 */

#ifndef INC_SENSORDATA_H_
#define INC_SENSORDATA_H_
#include "ButtonHandle.h"  // Assuming this header defines ButtonHandle
#include <stdint.h>

#define MAX_BUTTONS 3  // Số lượng nút bấm bạn muốn theo dõi

typedef struct {
    ButtonHandle buttons[MAX_BUTTONS];  // Mảng các nút bấm
    uint16_t temperature;               // Nhiệt độ cảm biến
    void (*ButtonChange)(button_state_data_s);  // Callback khi nút bấm thay đổi
    void (*TempChange)(uint16_t);       // Callback khi nhiệt độ thay đổi
} SensorData;
void SensorDataInit(SensorData *sensorData);
void SensorDataUpdate(SensorData *sensorData);
#endif /* INC_SENSORDATA_H_ */
