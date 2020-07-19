#ifndef _I2C_H
#define _I2C_H


#include "common_marcos.h"
#include "std_types.h"
#include "micro_config.h"

#include "Port.h"


#define SCL_PORT  (uint8)2
#define SCL_CHANNEL  (uint8)3
#define SCL_DIRECTION INPUT

#define SDA_PORT  (uint8)2
#define SDA_CHANNEL  (uint8)4
#define SDA_DIRECTION INPUT


/***************************************************************************************************
                             Function Prototypes
***************************************************************************************************/
void I2C_Init(void);
void I2C_Restart(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(uint8 );
uint8 I2C_Read(uint8);
/**************************************************************************************************/

#endif
