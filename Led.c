/******************************************************************************
 *
 * Module: FAN
 *
 * File Name: led.c
 *
 * Description: Source file for the LED driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/

#include "Led.h"

static Port_Config  g_LED_Config;

static void LED_setConfigurations(void)
{
	g_LED_Config.port = LED_PORT; 
	g_LED_Config.pin_num = LED_PIN_NUM; 
	g_LED_Config.direction = OUTPUT; 
}

 void LED_init(void)
{
	LED_setConfigurations(); 
	Port_SetDirection(&g_LED_Config); 
	Dio_WriteChannel(LED_IDX,LED_OFF); 
}

void LED_On(void)
{
	Dio_WriteChannel(LED_IDX,LED_ON); 
}

void LED_Off(void)
{
	Dio_WriteChannel(LED_IDX,LED_OFF); 
}
void LED_toggle(void)
{
	Dio_LevelType state = Dio_FlipChannel(LED_IDX);
}
