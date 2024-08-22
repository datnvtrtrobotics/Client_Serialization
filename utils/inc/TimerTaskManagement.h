/*
 * TimerTaskManagement.h
 *
 *  Created on: Aug 20, 2024
 *      Author: tdat
 */

#ifndef INC_TIMERTASKMANAGEMENT_H_
#define INC_TIMERTASKMANAGEMENT_H_

#include <stdint.h>
#include "DataPackage.h"

#define MAX_TIMERS 20

typedef struct {
    uint16_t previous_time;
    uint16_t interval;
    messageID DataID;
} TimerTask;

typedef struct {
    TimerTask TimerList[MAX_TIMERS];
} TimerTaskManagement;

int TimerTaskManagement_run(uint16_t current_time);
void InitTimerTasks();
#endif /* INC_TIMERTASKMANAGEMENT_H_ */
