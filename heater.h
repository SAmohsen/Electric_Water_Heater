/******************************************************************************
 *
 * Module: HEATER
 *
 * File Name: heater.h
 *
 * Description: Header file for the Heater driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/
#ifndef HEATER_H
#define	HEATER_H

#include "std_types.h"
#include "micro_config.h"
#include "common_marcos.h"

#include "DIO.h"
#include "Port.h"


#define HEATER_ON STD_HIGH 
#define HEATER_OFF STD_LOW


/* Heater PRE compile Configuration */
#define HEATER_PORT (uint8)2  /*PORTC*/
#define HEATER_PIN_NUM (uint8)5 /*Pin 5 "heater" */
#define HEATER_DIRECTION OUTPUT /*Heater is output*/
#define HEATER_IDX DioConf_HEATING_ELEMENT_INDEX

/*******************************************************************************
 *                              Function ProtoTypes                             *
 *******************************************************************************/
void Heater_init(void);
void Heater_On(void);
void Heater_Off(void);


#endif	/* HEATER_H */

