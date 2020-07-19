/* 
 * File:   ElectricWaterHeater.h
 * Author: sayed
 *
 * Created on July 16, 2020, 10:01 AM
 */

#ifndef ELECTRICWATERHEATER_H
#define	ELECTRICWATERHEATER_H

#include "micro_config.h"
#include "common_marcos.h"
#include "std_types.h"

/*MCAL*/
#include "Port.h"
#include "DIO.h"
#include "DIO_cfg.h"
#include "DIO_PBcfg.h"
#include "ADC.h"

/*HAL*/
#include "SW.h"
#include "LM35.h"
#include "fan.h"
#include "heater.h"
//#include "DISP.h
#include "SSD.h"
#include "external_eeprom.h"
#include "Led.h"





/*************************************************************************************
 	 	 	 	 	 	 	 	PreCompile Configurations
 ************************************************************************************/
#define HEATER_INITIAL_TEMPERATURE 60 
#define NO_WATER_TEMPERATURE_READINGS 10
#define MINI_TEMPERATURE_SET 35
#define MAX_TEMPERATURE_SET 75
#define TEMPERATURE_BASE 5 
#define TEMPERATURE_ERROR_BASE 5 
#define EEPROM_REQUIRED_TEMP_ADDR (uint8)0xc0

/*************************************************************************************
 	 	 	 	 	 	 	 	 Module DataTypes
 ************************************************************************************/
typedef struct {
uint8 g_avg_waterTemp ;
uint8 g_Curr_temp_readings ;
uint8 g_required_Temp ;
uint16 g_curr_waterTemp ;
    
}EWH_TempSettingsType;
typedef struct  {
    unsigned char SW_pressed_flag : 1;
    unsigned char temp_sensing_time_flag : 1;
    unsigned char display_time_flag : 1;
    unsigned char led_time_flag : 1;
    unsigned char pressed_Sw_timeout : 1;
    unsigned char SW_time_flag : 1;
    unsigned char RESERVED : 2;
}EWH_SysFlagsType ;

typedef struct  {
    uint8 tempsensingTime;
    uint16 lastpressedswTime;
}EWH_SysTimesType;

typedef enum {
    OFF_STATE , TIME_SETTING_STATE , TEMP_CONTROLLING_STATE
}Heater_states ; 





/*******************************************************************************
 *                              Function ProtoTypes                             *
 *******************************************************************************/


/************************************************************************************
* Task Name: SW_Task
* Description: -Periodic Task to update Switch Samples and Update Switch States.
*              -Switch Samples should be update once every 5 ms
************************************************************************************/
void SW_Task(void) ;

/************************************************************************************
* Task Name: TempSensing_Task
* Description:  -Periodic Task to Update current Water Temperature based On 
*                   Required Number OF Temp Readings Sample .
*               -Temperature should be sensed once every 100 ms
************************************************************************************/
void TempSensing_Task(void) ;

/************************************************************************************
* Task Name: Display_Task
* Description:  -Periodic Task to Update Seven Segment Display .
*               -Display should be updated  once every 5 ms.
************************************************************************************/
void Display_Task(void) ;

/************************************************************************************
* Service Name: TempControl_State
* Parameters (in): None
* Return value:None
* Description: Function to Start Controling Water Temperature.
************************************************************************************/
void TempControl_State(void) ;

/************************************************************************************
* Service Name: TempSetting_State
* Parameters (in): None
* Return value:None
* Description: Function to Set Required Water Temperature.
************************************************************************************/
void TempSetting_State(void) ;

/************************************************************************************
* Service Name: EWH_updateState
* Parameters (in): None
* Return value:None
* Description: Function to update Operating Mode  Electrical Water Heater System.
************************************************************************************/
void EWH_updateState(void);

/************************************************************************************
* Service Name: EWH_initTask
* Parameters (in): None
* Return value:None
* Description: Function to Initialize Electrical Water Heater System.
************************************************************************************/
void EWH_initTask(void) ;



/*******************************************************************************
 *                          External Variables                                   *
 *******************************************************************************/
extern Heater_states g_curr_heater_state ;/*global Variable To Hold Current Heater State*/
extern EWH_TempSettingsType EWH_TempSettings; /*global Strucure To Hold Temperature Setting*/
extern EWH_SysTimesType EWH_SysTimes;/*global Strucure To Hold Periodic Tasks Times*/
extern EWH_SysFlagsType EWH_SysFlags;/*global bitfield To Hold System Flags*/

#endif	/* ELECTRICWATERHEATER_H */

