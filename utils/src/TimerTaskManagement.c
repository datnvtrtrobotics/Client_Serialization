/*
 * TimerTaskManagement.c
 *
 *  Created on: Aug 20, 2024
 *      Author: tdat
 */
#include "TimerTaskManagement.h"
TimerTaskManagement TimerManager;

int TimerTaskManagement_run(uint16_t current_time) {
    for (int i = 0; i < MAX_TIMERS; i++) {
        TimerTask *task = &TimerManager.TimerList[i];
        if (task->interval != 0 && (current_time - task->previous_time) >= task->interval) {
            task->previous_time = current_time;
            return task->DataID;
        }
    }
    return -1;
}
int AddTimerTask(TimerTask* task) {
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (TimerManager.TimerList[i].interval == 0) {
            TimerManager.TimerList[i] = *task;
            return 0;
        }
    }
    return -1;
}
void InitTimerTasks() {
    TimerTask dateStreamTask = {0, 2000, date_stream_data_id};  // 0.5 Hz
    TimerTask timeStreamTask = {0, 1000, time_stream_data_id};         // 1 Hz
    TimerTask adcStreamTask = {0, 20, adc_stream_data_id};             // 50 Hz
    TimerTask helloWorldTask = {0, 500, hello_world_data_id};          // 2 Hz

    // Thêm các nhiệm vụ vào TimerManager
    AddTimerTask(&dateStreamTask);
    AddTimerTask(&timeStreamTask);
    AddTimerTask(&adcStreamTask);
    AddTimerTask(&helloWorldTask);
}
