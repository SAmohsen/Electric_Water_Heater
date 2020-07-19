/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for Port Module.
 *
 * Author: Sayed Mohsen
 ******************************************************************************/

#include "Port.h"

void Port_SetDirection(const Port_Config * ConfigPtr) {
   volatile  uint8 * DDR_Ptr = NULL_PTR;
    /* point to the required DDR Register */
    switch (ConfigPtr->port) {
        case 0: DDR_Ptr = &TRISA;
            break;
        case 1: DDR_Ptr = &TRISB;
            break;
        case 2: DDR_Ptr = &TRISC;
            break;
        case 3: DDR_Ptr = &TRISD;
            break;
        case 4: DDR_Ptr = &TRISE;
            break;
    }
    if (ConfigPtr->direction == INPUT) {
        SET_BIT(*DDR_Ptr, ConfigPtr->pin_num); // set the corresponding bit in the DDR register to configure it as input pin
    } else if (ConfigPtr->direction == OUTPUT) {
        CLR_BIT(*DDR_Ptr, ConfigPtr->pin_num); // CLR the corresponding bit in the DDR register to configure it as output pin
    }
}

void Port_SetPortDirection(const Port_ConfigPort * ConfigPtr) {
 volatile   uint8 * DDR_Ptr = NULL_PTR;
    /* point to the required DDR Register */
    switch (ConfigPtr->port) {
        case 0: DDR_Ptr = &TRISA;
            break;
        case 1: DDR_Ptr = &TRISB;
            break;
        case 2: DDR_Ptr = &TRISC;
            break;
        case 3: DDR_Ptr = &TRISD;
            break;
        case 4: DDR_Ptr = &TRISE;
            break;

    }
    if (ConfigPtr->direction == INPUT) {
        *DDR_Ptr = PORT_HIGH;
    } else if (ConfigPtr->direction == OUTPUT) {
        *DDR_Ptr = PORT_LOW;
    }
}
