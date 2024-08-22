/*
 * GPIO_Driver.h
 *
 *  Created on: Aug 19, 2024
 *      Author: tdat
 */

#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_
#include "stm32f1xx_hal.h"
#include <stdint.h>

typedef struct {
    GPIO_TypeDef *port; // Correct type for port
    uint16_t pin;
} GPIODriver;

uint8_t gpio_read(GPIODriver *gpio, uint16_t pin);
void gpio_write(GPIODriver *gpio, uint16_t pin, uint8_t value);

#endif /* INC_GPIO_DRIVER_H_ */
