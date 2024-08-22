/*
 * GPIO_Driver.c
 *
 *  Created on: Aug 19, 2024
 *      Author: tdat
 */

#include "GPIO_Driver.h"


uint8_t gpio_read(GPIODriver *gpio, uint16_t pin) {
    return (uint8_t)HAL_GPIO_ReadPin(gpio->port, pin);
}

void gpio_write(GPIODriver *gpio, uint16_t pin, uint8_t value) {
    HAL_GPIO_WritePin(gpio->port, pin, (GPIO_PinState)value);
}
