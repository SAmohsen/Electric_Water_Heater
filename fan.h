/******************************************************************************
 *
 * Module: FAN
 *
 * File Name: Fan.h
 *
 * Description: Header file for the Fan driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/

#ifndef FAN_H
#define	FAN_H


#include "std_types.h"
#include "micro_config.h"
#include "common_marcos.h"

#include "DIO.h"
#include "Port.h"


#define FAN_ON STD_HIGH 
#define FAN_OFF STD_LOW

/* Heater PRE compile Configuration */
#define FAN_PORT (uint8)2  /*PORTC*/
#define FAN_PIN_NUM (uint8)2 /*Pin 2 "fan" */
#define FAN_DIRECTION OUTPUT /*Fan is Output*/

#define FAN_IDX DioConf_COOLING_ELEMENT_INDEX

/*******************************************************************************
 *                              Function ProtoTypes                             *
 *******************************************************************************/
void Fan_init(void);
void Fan_On(void);
void Fan_Off(void);


#endif	/* FAN_H */

