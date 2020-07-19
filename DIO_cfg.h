/*
 * DIO_cfg.h
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */

#ifndef DIO_CFG_H_
#define DIO_CFG_H_



#include "std_types.h"



/*
 *
 *
 *configure number of channels and  number of ports
 *
 */

#define DIO_CONFIGURED_CHANNELS (8U)
#define DIO_CONFIGURED_PORTS (1U)


/*SET your configurations */

/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_UP_TEMPERATURE_SW_INDEX       (uint8)0x00
#define DioConf_DOWN_TEMPERATURE_SW_INDEX     (uint8)0x01
#define DioConf_HEATER_POWER_SW_INDEX        (uint8)0x02
#define DioConf_COOLING_ELEMENT_INDEX        (uint8)0x03
#define DioConf_HEATING_ELEMENT_INDEX        (uint8)0x04
#define DioConf_SSD_DISP1_INDEX        (uint8)0x05
#define DioConf_SSD_DISP2_INDEX        (uint8)0x06
#define DioConf_LED_CHANNEL_ID_INDEX        (uint8)0x07



#define DioConf_UP_TEMPERATURE_SW_CHANNEL_NUMBER      (uint8)2
#define DioConf_DOWN_TEMPERATURE_SW_CHANNEL_NUMBER    (uint8)1
#define DioConf_HEATER_POWER_SW_CHANNEL_NUMBER        (uint8)0
#define DioConf_COOLING_ELEMENT_CHANNEL_NUMBER        (uint8)2
#define DioConf_HEATING_ELEMENT_CHANNEL_NUMBER        (uint8)5
#define DioConf_SSD_DISP1_CHANNEL_NUMBER        (uint8)0x02
#define DioConf_SSD_DISP2_CHANNEL_NUMBER        (uint8)0x03
#define DioConf_LED_CHANNEL_NUM             (uint8)7


#define DioConf_UP_TEMPERATURE_SW_PORT_NUMBER      (uint8)1
#define DioConf_DOWN_TEMPERATURE_SW_PORT_NUMBER    (uint8)1
#define DioConf_HEATER_POWER_SW_PORT_NUMBER        (uint8)1
#define DioConf_COOLING_ELEMENT_PORT_NUMBER        (uint8)2
#define DioConf_HEATING_ELEMENT_PORT_NUMBER        (uint8)2
#define DioConf_SSD_DISP1_PORT_NUMBER        (uint8)0x00
#define DioConf_SSD_DISP2_PORT_NUMBER        (uint8)0x00
#define DioConf_LED_PORT_NUM                (uint8)1










#define DioConf_SSD_PORT_INDEX (uint8)0 
#define DioConf_SSD_PORT_NUMBER (uint8)3


#endif /* DIO_CFG_H_ */
