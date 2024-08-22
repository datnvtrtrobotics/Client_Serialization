/*
 * ADC.h
 *
 *  Created on: Aug 19, 2024
 *      Author: tdat
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"
extern ADC_HandleTypeDef hadc1;

typedef struct  mcu_temperature_data_s {
	uint16_t pin_value[2];
	uint16_t mcu_temperature_in_c;
}ADCDriver;

uint16_t adc_getValue(ADCDriver *adc, uint16_t pin);
uint16_t adc_getTemp(ADCDriver *adc);

void adc_update(ADCDriver *adc);

#endif /* INC_ADC_H_ */
