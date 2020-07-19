/******************************************************************************
 *
 * Module: SWITCH
 *
 * File Name: SW.C
 *
 * Description: Source file for the Switch "BTN" driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/

#include "SW.h"

Port_Config *g_SW_configs = NULL_PTR;
uint8 g_sw_states[NO_OF_CONFIGURED_SWITCHES] = { SW_RELEASED };

static void SW_setConfigurations(Sw_ConfigType *config_PTR) {
	uint8 itr = 0;
	if (config_PTR != NULL_PTR) {
		g_SW_configs = config_PTR->SW_configured_channels;
		for (itr = 0; itr < NO_OF_CONFIGURED_SWITCHES; itr++) {
			Port_SetDirection(&g_SW_configs[itr]);
		}
	}
}

void SW_init() {
	SW_setConfigurations(&SW_Configurations);
}

void SW_updateState(uint8 sw_index) {
	uint8 sw_state = Dio_ReadChannel(sw_index);
	uint8 dummydelay;
	if (SW_PRESSED == sw_state) {
		dummydelay = sw_state;
        __delay_ms(100);
		sw_state = Dio_ReadChannel(sw_index);
		if (SW_PRESSED == sw_state) {
			g_sw_states[sw_index] = SW_PRESSED;
		} else {
			g_sw_states[sw_index] = SW_RELEASED;
		}
	} else {
		g_sw_states[sw_index] = SW_RELEASED;
	}
}
uint8 SW_UpdateStates() {
    uint8 itr;
    uint8 new_pressed_Sw_flag = SW_RELEASED ; 
    for (itr = 0; itr < NO_OF_CONFIGURED_SWITCHES; itr++) {
        if(g_sw_states[itr]==SW_PRESSED)
        {
            new_pressed_Sw_flag =1; 
            break ; 
        }
    }
    return new_pressed_Sw_flag ; 
}

uint8 SW_getState(uint8 sw_index) {
	return g_sw_states[sw_index];
}
void SW_updateSamples(){
    SW_updateState(DioConf_DOWN_TEMPERATURE_SW_INDEX);
    SW_updateState(DioConf_UP_TEMPERATURE_SW_INDEX);
    SW_updateState(DioConf_HEATER_POWER_SW_INDEX);
}
