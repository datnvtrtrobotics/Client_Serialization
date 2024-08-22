/*
 * ButtonHandle.c
 *
 *  Created on: Aug 20, 2024
 *      Author: tdat
 */
#include "ButtonHandle.h"

#define HOLD_THRESHOLD_MS 2000   // Thời gian giữ nút để được coi là BUTTON_HOLD (2 giây)
#define DOUBLE_CLICK_THRESHOLD_MS 500 // Thời gian giữa hai lần nhấn để được coi là BUTTON_DOUBLE_CLICK (500 ms)

uint8_t ButtonHandle_polling(ButtonHandle *button) {
    uint8_t currentState = gpio_read(&button->gpio, button->gpio.pin);
    uint32_t currentTime = HAL_GetTick();

    if (currentState == GPIO_PIN_SET) {
        if (button->waitingForDoubleClick) {
            if (currentTime - button->lastPressTime < DOUBLE_CLICK_THRESHOLD_MS) {
                button->waitingForDoubleClick = false;
                return BUTTON_DOUBLE_CLICK;
            }
        } else if (currentTime - button->lastPressTime > HOLD_THRESHOLD_MS) {
            return BUTTON_HOLD;
        } else {
            button->lastPressTime = currentTime;
            return BUTTON_PRESSED;
        }
    } else {
        if (currentTime - button->lastPressTime < DOUBLE_CLICK_THRESHOLD_MS) {
            button->waitingForDoubleClick = true;
        } else {
            button->waitingForDoubleClick = false;
        }
        return BUTTON_RELEASED;
    }
    return button->state;
}
int ButtonHandle_eventOnChange(ButtonHandle *button) {
    ButtonState newState = ButtonHandle_polling(button);

    if (newState != button->state) {
        button->state = newState;
        return 1;
    }
    return 0;
}
