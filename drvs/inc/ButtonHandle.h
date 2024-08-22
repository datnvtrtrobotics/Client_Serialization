/*
 * ButtonHandle.h
 *
 *  Created on: Aug 20, 2024
 *      Author: tdat
 */
#ifndef INC_BUTTONHANDLE_H_
#define INC_BUTTONHANDLE_H_
#include "GPIO_Driver.h"
#include <stdbool.h>

typedef enum {
    BUTTON_PRESSED = 1,
    BUTTON_RELEASED = 0,
    BUTTON_HOLD = 2,
    BUTTON_DOUBLE_CLICK = 3
} ButtonState;
typedef struct {
    uint8_t button_id;
    uint16_t button_state;  // Trạng thái của nút bấm (nhấn, giữ, double click, nhả)
} button_state_data_s;
typedef struct {
    GPIODriver gpio;
    ButtonState state;
    uint32_t lastPressTime;   // Thời gian lần nhấn nút cuối cùng
    bool waitingForDoubleClick;
} ButtonHandle;

int ButtonHandle_eventOnChange(ButtonHandle *button);

#endif /* INC_BUTTONHANDLE_H_ */
