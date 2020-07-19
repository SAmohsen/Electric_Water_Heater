/******************************************************************************
 *
 * Module: Switch
 *
 * File Name: SW_PBcfg.c
 *
 * Description: Post Build Configuration Source file for SW Module.
 *
 * Author: sayed mohsen
 ******************************************************************************/

#include "SW.h"

Sw_ConfigType SW_Configurations = {
    .SW_configured_channels[DioConf_UP_TEMPERATURE_SW_INDEX ].port = UP_TEMPERATURE_SW_PORT,
    .SW_configured_channels[DioConf_UP_TEMPERATURE_SW_INDEX ].pin_num = UP_TEMPERATURE_SW_CHANNEL,
    .SW_configured_channels[DioConf_UP_TEMPERATURE_SW_INDEX ].direction = INPUT,

    .SW_configured_channels[DioConf_DOWN_TEMPERATURE_SW_INDEX ].port = DOWN_TEMPERATURE_SW_PORT,
    .SW_configured_channels[DioConf_DOWN_TEMPERATURE_SW_INDEX ].pin_num = DOWN_TEMPERATURE_SW_CHANNEL,
    .SW_configured_channels[DioConf_DOWN_TEMPERATURE_SW_INDEX ].direction = INPUT,

    .SW_configured_channels[DioConf_HEATER_POWER_SW_INDEX ].port = HEATER_POWER_SW_PORT,
    .SW_configured_channels[DioConf_HEATER_POWER_SW_INDEX ].pin_num = HEATER_POWER_SW_CHANNEL,
    .SW_configured_channels[DioConf_HEATER_POWER_SW_INDEX ].direction = INPUT,
};
