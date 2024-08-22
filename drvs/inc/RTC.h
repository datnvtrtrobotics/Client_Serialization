/*
 * RTC.h
 *
 *  Created on: Aug 19, 2024
 *      Author: tdat
 */

#ifndef INC_RTC_H_
#define INC_RTC_H_
#include <stdint.h>
#include "stm32f1xx_hal.h"

extern RTC_HandleTypeDef hrtc;

typedef struct date_stream_data_s {
 uint32_t day;
 uint32_t month;
 uint32_t year;
}RTCDate;

typedef struct time_stream_data_s {
 uint8_t hour;
 uint16_t minute;
 uint16_t second;
}RTCTime;

void rtc_getDate(RTCDate *date);
void rtc_getHour(RTCTime *time);

#endif /* INC_RTC_H_ */
