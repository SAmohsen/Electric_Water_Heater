/******************************************************************************
 *
 * Module: FAN
 *
 * File Name: Fan.c
 *
 * Description: Source file for the Fan driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/

#include "fan.h"


static Port_Config g_coolingElement_config; /*global variable To Hold Cooling element "Fan" configurations*/

static void fan_setConfigurations() {
    /* Cooler Set Configurations*/
    g_coolingElement_config.port = FAN_PORT; /*PORTC*/
    g_coolingElement_config.pin_num = FAN_PIN_NUM; /*Pin 2 "fan" */
    g_coolingElement_config.direction = FAN_DIRECTION; /*fan is output*/
}

void Fan_init() {
    fan_setConfigurations();
    Port_SetDirection(&g_coolingElement_config);
    Fan_Off(); 
}

void Fan_On() {
    Dio_WriteChannel(FAN_IDX, FAN_ON);
}

void Fan_Off() {
    Dio_WriteChannel(FAN_IDX, FAN_OFF);
}
