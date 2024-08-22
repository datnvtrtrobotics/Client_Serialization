/*
 * circularbf.h
 *
 *  Created on: Aug 19, 2024
 *      Author: tdat
 */

#ifndef INC_CIRCULAR_BF_H_
#define INC_CIRCULAR_BF_H_
#include <stdint.h>

#define BUFFER_SIZE 256
typedef struct {
	uint8_t buffer[BUFFER_SIZE];
	volatile uint16_t head;
	volatile uint16_t tail;
} CircularBuffer;

int CircularBuffer_Write(CircularBuffer *cb, uint8_t data);
int CircularBuffer_Read(CircularBuffer *cb, uint8_t *data);

#endif /* INC_CIRCULAR_BF_H_ */
