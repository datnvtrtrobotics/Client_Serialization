/*
 * RTC.c
 *
 *  Created on: Aug 19, 2024
 *      Author: tdat
 */

#include "RTC.h"

void rtc_getDate(RTCDate *date) {
    RTC_DateTypeDef sDate;
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
    date->day = sDate.Date;
    date->month = sDate.Month;
    date->year = sDate.Year;
}

void rtc_getHour(RTCTime *time) {
    RTC_TimeTypeDef sTime;
    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    time->hour = sTime.Hours;
    time->minute = sTime.Minutes;
    time->second = sTime.Seconds;
}
