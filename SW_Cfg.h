/*
 * SW_Cfg.h
 *
 *  Created on: Jul 4, 2020
 *      Author: sayed
 */

#ifndef HAL_SW_SW_CFG_H_
#define HAL_SW_SW_CFG_H_

#include "DIO.h"

#define NO_OF_CONFIGURED_SWITCHES (3U)

#define UP_TEMPERATURE_SW_PORT DioConf_UP_TEMPERATURE_SW_PORT_NUMBER
#define UP_TEMPERATURE_SW_CHANNEL DioConf_UP_TEMPERATURE_SW_CHANNEL_NUMBER

#define DOWN_TEMPERATURE_SW_PORT DioConf_DOWN_TEMPERATURE_SW_PORT_NUMBER
#define DOWN_TEMPERATURE_SW_CHANNEL DioConf_DOWN_TEMPERATURE_SW_CHANNEL_NUMBER


#define HEATER_POWER_SW_PORT DioConf_HEATER_POWER_SW_PORT_NUMBER
#define HEATER_POWER_SW_CHANNEL DioConf_HEATER_POWER_SW_CHANNEL_NUMBER

#endif /* HAL_SW_SW_CFG_H_ */
