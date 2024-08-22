/*
 * uart.h
 *
 *  Created on: Aug 19, 2024
 *      Author: tdat
 */

#ifndef INC_UART_H_
#define INC_UART_H_
#include "stm32f1xx_hal.h"

typedef struct {
    uint32_t baudRate;
    uint32_t wordLength;
    uint32_t stopBits;
    uint32_t parity;
} UART_Config;

typedef struct {
    UART_HandleTypeDef huart;
    UART_Config config;
    uint8_t isInitialized;
} UART_Driver;
extern UART_Driver uart1;
extern UART_Driver uart2;
extern UART_Driver uart3;

int UART_Init(UART_Driver *uart, UART_Config config);
void send_byte(UART_HandleTypeDef *huart, uint8_t byte);
void UART_SendString(UART_HandleTypeDef *huart, const char *str);

#endif /* INC_UART_H_ */
