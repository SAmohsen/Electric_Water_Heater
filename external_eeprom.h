/* 
 * File:   external_eeprom.h
 * Author: sayed
 *
 * Created on July 18, 2020, 6:31 AM
 */

#ifndef EXTERNAL_EEPROM_H
#define	EXTERNAL_EEPROM_H

#include "micro_config.h"
#include "common_marcos.h"
#include "std_types.h"

#include "i2c.h"

#define EEPROM_ADDRESS_WRITE_OPERATION        0xA0
#define EEPROM_ADD_READ_OPERATION         0xA1


void externalEEPROM_init (void) ; 
void externalEEPROM_writeU8Data (uint8 Data, uint8 Addr) ; 
void externalEEPROM_readU8Data (uint8* Data, uint8 Addr) ; 

#endif	/* EXTERNAL_EEPROM_H */

