 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for Port Module.
 *
 * Author: Sayed Mohsen
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H


#include "std_types.h"
#include "common_marcos.h"
#include "micro_config.h"


#define OUTPUT    (0U)
#define INPUT     (1U)

/****************************************************************************************************************/
/* Description: Structure to describe each individual PIN contains:
 *	1. the PORT Which the pin belongs to. 0, 1, 2 or 3
 *	2. the number of the pin in the PORT.
 *  3. the direction of pin --> INPUT or OUTPUT
 */
typedef struct 
{
	uint8 port; 
	uint8 pin_num; 
	uint8 direction;
}Port_Config;

typedef struct 
{
	uint8 port;  
	uint8 direction;
}Port_ConfigPort;




/***************************************************************************************************************/

/* configure the PIN to input or output pin */
void Port_SetDirection(const Port_Config *s_Config_Msg );
void Port_SetPortDirection(const Port_ConfigPort * ConfigPtr) ;
    
#endif /* PORT_H */
