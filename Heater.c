/******************************************************************************
 *
 * Module: HEATER
 *
 * File Name: Heater.c
 *
 * Description: Source file for the Heater driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/

#include "heater.h"

static Port_Config g_HeatingElement_config; /*global variable To Hold Heating element "Heater" configurations*/

static void Heater_setConfigurations() {
    /* Heater Set Configurations*/
    g_HeatingElement_config.port = HEATER_PORT; /*PORTC*/
    g_HeatingElement_config.pin_num = HEATER_PIN_NUM; /*Pin 5 "Heater"*/
    g_HeatingElement_config.direction = HEATER_DIRECTION; /*Heater is output*/
}

void Heater_init() {
    Heater_setConfigurations();
    Port_SetDirection(&g_HeatingElement_config);
    Heater_Off(); 
}

void Heater_On() {
    Dio_WriteChannel(HEATER_IDX, HEATER_ON);
}

void Heater_Off() {
    Dio_WriteChannel(HEATER_IDX, HEATER_OFF);
}