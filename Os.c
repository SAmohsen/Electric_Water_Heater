/*
 * Os.c
 *
 *  Created on: Jan 16, 2020
 *      Author: sayedMohsen
 */

#include "Os.h"
#include "ElectricWaterHeater.h"
#include "timer.h"



void Os_start(void) {

    /* Set the Call Back function call to Scheduler_New_Timer_Tick*/
    Tmr1_setCallback(Os_newTimerTick);
    TMR1_INTERRUPT_ENABLE();

    /* Execute the Init Task */
    EWH_initTask();

    /*Enable Interrupts */
    PERIPHRAL_INTERRUPT_ENABLE();
    SEI();
    
    /*Start the System Timer */
    SysTimer_start();

    /* Start the Os Scheduler */
    Os_sch();
}

uint8 sw = 0 ; 

/* Function called by the Timer Driver in the MCAL layer using the call back pointer */

void Os_newTimerTick() {
    EWH_SysTimes.tempsensingTime++;
    EWH_SysTimes.lastpressedswTime++;
    sw++; 
    if (TEMP_SENSING_PERIOD == EWH_SysTimes.tempsensingTime)
    {
        EWH_SysFlags.temp_sensing_time_flag = 1;
        EWH_SysTimes.tempsensingTime = 0;
    }
    
    if (EWH_SysFlags.SW_pressed_flag == 1)
    {
        EWH_SysTimes.lastpressedswTime = 0;
    } 
   if (PRESSED_SW_TIMEOUT == EWH_SysTimes.lastpressedswTime)
    {
        EWH_SysFlags.pressed_Sw_timeout = 1;
        EWH_SysTimes.lastpressedswTime = 0;
    }

    EWH_SysFlags.SW_time_flag = 1;
    if(sw)
    {
    EWH_SysFlags.display_time_flag = 1;
    sw = 0 ; 
    }
    TMR1L = 0x05;
    TMR1H = 0xf5;
}

extern void Active_Task() ; 
void Os_sch() {
    while (1) {
        EWH_updateState();
        /*Run Tasks At Their Scheduled Time*/
        if (EWH_SysFlags.display_time_flag == 1)
        {
            Display_Task();
            EWH_SysFlags.display_time_flag = 0;
        }
        if (EWH_SysFlags.temp_sensing_time_flag == 1)
        {
            TempSensing_Task();
            EWH_SysFlags.temp_sensing_time_flag = 0;
        }
        if (EWH_SysFlags.SW_time_flag == 1) 
        {
            SW_Task();
            EWH_SysFlags.SW_time_flag = 0;
        }
     if (EWH_SysFlags.pressed_Sw_timeout == 1)
        {
            Active_Task() ; 
            EWH_SysFlags.pressed_Sw_timeout = 0;
        }
    }

}