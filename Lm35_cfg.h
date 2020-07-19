/******************************************************************************
 *
 * Module: LM35
 *
 * File Name: lm35_cfd.h
 *
 * Description: Pre-Compile Configuration Header file for lm35 Module.
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/
#ifndef HAL_LM35_LM35_CFG_H_
#define HAL_LM35_LM35_CFG_H_
#include "LM35.h"


#define lm35_PORT (uint8)0  /*PORTA*/
#define lm35_PIN_NUM (uint8)2 /*Pin 2 */
#define lm35_DIRECTION INPUT /*Lm35 is input*/

#define LM35_ADC_CHANNEL 2   


#endif /* HAL_LM35_LM35_CFG_H_ */
