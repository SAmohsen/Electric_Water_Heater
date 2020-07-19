/*
 * DIO_PBcfg.c
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */

#include "std_types.h"
#include "DIO.h"
#include "DIO_cfg.h"


/*post build configurations */
 Dio_ConfigType DIO_configuration = {
		.Dio_channels[DioConf_UP_TEMPERATURE_SW_INDEX ].port_number =DioConf_UP_TEMPERATURE_SW_PORT_NUMBER,
		.Dio_channels[DioConf_UP_TEMPERATURE_SW_INDEX ].channel_number =DioConf_UP_TEMPERATURE_SW_CHANNEL_NUMBER,

		.Dio_channels[DioConf_DOWN_TEMPERATURE_SW_INDEX ].port_number =DioConf_DOWN_TEMPERATURE_SW_PORT_NUMBER,
		.Dio_channels[DioConf_DOWN_TEMPERATURE_SW_INDEX ].channel_number =DioConf_DOWN_TEMPERATURE_SW_CHANNEL_NUMBER,

		.Dio_channels[DioConf_HEATER_POWER_SW_INDEX ].port_number =DioConf_HEATER_POWER_SW_PORT_NUMBER,
		.Dio_channels[DioConf_HEATER_POWER_SW_INDEX ].channel_number =DioConf_HEATER_POWER_SW_CHANNEL_NUMBER,

		.Dio_channels[DioConf_COOLING_ELEMENT_INDEX].port_number = DioConf_COOLING_ELEMENT_PORT_NUMBER,
		.Dio_channels[DioConf_COOLING_ELEMENT_INDEX].channel_number = DioConf_COOLING_ELEMENT_CHANNEL_NUMBER,



		.Dio_channels[DioConf_HEATING_ELEMENT_INDEX].port_number = DioConf_HEATING_ELEMENT_PORT_NUMBER,
		.Dio_channels[DioConf_HEATING_ELEMENT_INDEX].channel_number = DioConf_HEATING_ELEMENT_CHANNEL_NUMBER,
        
        .Dio_channels[DioConf_SSD_DISP1_INDEX].port_number=DioConf_SSD_DISP1_PORT_NUMBER ,
        .Dio_channels[DioConf_SSD_DISP1_INDEX].channel_number=DioConf_SSD_DISP1_CHANNEL_NUMBER ,
        
        .Dio_channels[DioConf_SSD_DISP2_INDEX].port_number=DioConf_SSD_DISP2_PORT_NUMBER ,
        .Dio_channels[DioConf_SSD_DISP2_INDEX].channel_number=DioConf_SSD_DISP2_CHANNEL_NUMBER ,
        
        
        .Dio_channels[DioConf_LED_CHANNEL_ID_INDEX].port_number=DioConf_LED_PORT_NUM ,
        .Dio_channels[DioConf_LED_CHANNEL_ID_INDEX].channel_number=DioConf_LED_CHANNEL_NUM ,
        
        .Dio_ports[DioConf_SSD_PORT_INDEX] = DioConf_SSD_PORT_NUMBER , 
        
};
