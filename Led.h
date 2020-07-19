/******************************************************************************
 *
 * Module: led
 *
 * File Name: led.h
 *
 * Description: Header file for the LED driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/
#ifndef LED_H
#define LED_H


#include "std_types.h"
#include "micro_config.h"
#include "common_marcos.h"

#include "DIO.h"
#include "Port.h"


#define LED_ON  STD_HIGH
#define LED_OFF STD_LOW

/* Heater PRE compile Configuration */
#define LED_IDX DioConf_LED_CHANNEL_ID_INDEX
#define LED_PORT DioConf_LED_PORT_NUM
#define LED_PIN_NUM DioConf_LED_CHANNEL_NUM


/*******************************************************************************
 *                              Function ProtoTypes                             *
 *******************************************************************************/
void LED_init(void);
void LED_On(void);
void LED_Off(void);
void LED_toggle(void);

#endif /* LED_H */
