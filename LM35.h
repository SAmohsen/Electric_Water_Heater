/******************************************************************************
 *
 * Module: LM35
 *
 * File Name: lm35.h
 *
 * Description: Header file for the lm35 "TEMP Sensor" driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/
#ifndef HAL_LM35_LM35_H_
#define HAL_LM35_LM35_H_

#include "std_types.h"
#include "common_marcos.h"
#include  "micro_config.h"

#include "Port.h"
#include "ADC.h"
#include "Lm35_cfg.h"


/*******************************************************************************
 *                              Function ProtoTypes                             *
 *******************************************************************************/
void LM35_Init(void);
uint16 LM35_ReadTemp(void);

#endif /* HAL_LM35_LM35_H_ */
