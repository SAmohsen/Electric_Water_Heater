/******************************************************************************
 *
 * Module: LM35
 *
 * File Name: lm35.c
 *
 * Description: Source file for the lm35 "TEMP Sensor" driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/
#include"LM35.h"

static Port_Config g_lm35_config ; 

static void lm35_setConfigurations()
{
    g_lm35_config.port = lm35_PORT ; 
    g_lm35_config.pin_num = lm35_PIN_NUM ; 
    g_lm35_config.direction = lm35_DIRECTION ; 
}
void LM35_Init(void)
{
	lm35_setConfigurations() ; 
    Port_SetDirection(&g_lm35_config);
}
uint16 LM35_ReadTemp()
{
	uint16 temp;
	float dig;
	float volt;
	dig = Adc_readChannel(LM35_ADC_CHANNEL) ;
	volt = (dig * 5) / 1023;
	volt = (volt) / 10;
	temp = volt * 1000;
	return temp;
}
