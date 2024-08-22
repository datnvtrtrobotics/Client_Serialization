/*
 * ADC.c
 *
 *  Created on: Aug 19, 2024
 *      Author: tdat
 */

#include "ADC.h"

uint16_t adc_getValue(ADCDriver *adc, uint16_t pin) {
    ADC_ChannelConfTypeDef sConfig = {0};
    sConfig.Channel = pin;
    sConfig.Rank = 1;
    sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;

    HAL_ADC_ConfigChannel(&hadc1, &sConfig);
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    uint16_t value = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    return value;
}

uint16_t adc_getTemp(ADCDriver *adc) {
    uint16_t temp = adc_getValue(adc, ADC_CHANNEL_TEMPSENSOR);
    return temp;
}

void adc_update(ADCDriver *adc) {
	adc->pin_value[0] = adc_getValue(adc, 0); // PA0
	adc->pin_value[1] = adc_getValue(adc, 1); // PA1

	adc->mcu_temperature_in_c = adc_getTemp(adc);
}
