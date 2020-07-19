/*
 * os.h
 *
 *  Created on: Jan 14, 2020
 *      Author: sayedMohsen
 */

#ifndef OS_H_
#define OS_H_

#include "timer.h"
#include "ElectricWaterHeater.h"
#include "INTHandlers.h"
/* Timer counting time in ms */
#define OS_BASE_TIME 2

#define DISPLAY_TIME 10 
#define TEMP_SENSING_PERIOD 100
#define PRESSED_SW_TIMEOUT 5000

/* Function responsible for:
 * 1. Initialize the Os
 * 2. Execute the Init Task
 * 3. Start the Scheduler to run the tasks
 */
void Os_start(void);

/* The Engine of the Os Scheduler used for switch between different tasks */
void Os_sch(void);

/* Function called by the Timer Driver in the MCAL layer using the call back pointer */
void Os_newTimerTick(void);

#endif /* OS_H_ */
