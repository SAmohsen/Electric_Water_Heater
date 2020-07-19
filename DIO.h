/*
 * DIO.h
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */

#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"
#include "common_marcos.h"
#include "micro_config.h"

#include "DIO_cfg.h"
#include "DIO_types.h"

#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)


/********************************************************************
 * 						Function ProtoTypes
 * ******************************************************************/
void Dio_Init(const Dio_ConfigType *ConfigPtr) ;

void Dio_WritePort(Dio_PortType PortId,
					Dio_PortLevelType Level
					);

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId) ;

void Dio_WriteChannel(Dio_ChannelType ChannelId,
					  Dio_LevelType Level) ;

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId) ;

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif /* DIO_H_ */
