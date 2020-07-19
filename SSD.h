/*
 * SSD.h
 *
 *  Created on: Dec 14, 2019
 *      Author: sayed
 */

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_marcos.h"
#include "Port.h"
#include "DIO.h"

#include "SSD_cfg.h"
#define SEVEN_SEGMENT_ENABLE_PORT PORTA

#define SEVENSEGMENT1_ENABLE 4
#define SEVENSEGMENT2_ENABLE 5


void Disp_init(void) ;
void Disp_updateValue(uint8 value) ; 
void Disp_turnDiplaysOff (void) ; 
void Disp_updateValue_blink(uint8 value) ; 

#endif /* SEVENSEGMENT_H_ */
