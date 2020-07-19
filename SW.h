/******************************************************************************
 *
 * Module: SWITCH
 *
 * File Name: SW.h
 *
 * Description: Header file for the Switch "BTN" driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/

#ifndef HAL_SW_SW_H_
#define HAL_SW_SW_H_

#include "std_types.h"
#include "common_marcos.h"
#include "micro_config.h"


#include "DIO.h"
#include "Port.h"

#include "SW_Cfg.h"

/* PUll up switches*/
#define SW_PRESSED  STD_LOW
#define SW_RELEASED STD_HIGH

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
typedef struct {
	Port_Config SW_configured_channels[NO_OF_CONFIGURED_SWITCHES] ;
}Sw_ConfigType;

/*******************************************************************************
 *                              Function ProtoTypes                              *
 *******************************************************************************/

void SW_init(void) ;
void SW_updateState(uint8 sw_index) ;
uint8 SW_UpdateStates(void) ;
uint8 SW_getState(uint8 sw_index) ;
void SW_updateSamples(void);
/******************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern Sw_ConfigType SW_Configurations ;

#endif /* HAL_SW_SW_H_ */
