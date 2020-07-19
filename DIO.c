/*
 * DIO.c
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */

#include "DIO.h"

static uint8 Dio_status = DIO_NOT_INITIALIZED;
static  Dio_ConfigChannel *Dio_configuredChannels = NULL_PTR;
static Dio_PortType  *Dio_configuredPorts = NULL_PTR ;

void Dio_Init(const Dio_ConfigType *ConfigPtr) {
	boolean error = FALSE  ;
	/*Error Checking */
	if (NULL_PTR == ConfigPtr)
	{
		/* report Null pointer error */
		error = TRUE ;
	}
	else
	{
		/* no action required */
	}

	if (FALSE == error)
	{
		Dio_configuredChannels = ConfigPtr->Dio_channels ;
		Dio_configuredPorts = ConfigPtr->Dio_ports ;
		Dio_status = DIO_INITIALIZED ;
	}
	else
	{
		/* no action required */

	}

}

/* Function for DIO write Channel API */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	 volatile uint8 *port_ptr = NULL_PTR ;
	boolean error = FALSE ;

	if (DIO_NOT_INITIALIZED == Dio_status)
	{
		/* report DIO not INITIALIZED  error */
		error = TRUE  ;

	}
	else
	{
		/* no action required */
	}
	if (DIO_CONFIGURED_PORTS<=PortId)
	{
		/*report error parameters*/
		error = TRUE ;

	}
	else
	{

	}

	if (FALSE == error)
	{
		/*get port address address*/
		switch (Dio_configuredPorts[PortId])
		{
		case 0: port_ptr = &PORTA ;
		break ;
		case 1: port_ptr = &PORTB ;
		break;
		case 2: port_ptr = &PORTC;
		break ;
		case 3: port_ptr = &PORTD;
		break ;
        case 4: port_ptr = &PORTE;
		break ;
		}

		*port_ptr= Level ;
	}
	else
	{

	}
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId) {
volatile	uint8 *pin_ptr = NULL_PTR;
	Dio_PortLevelType portLevel ;
	boolean error = FALSE;

	if (DIO_NOT_INITIALIZED == Dio_status)
	{
		/* report DIO not INITIALIZED  error */
		error = TRUE;
	}
	else
	{
		/* no action required */
	}
	if (DIO_CONFIGURED_PORTS <= PortId)
	{
		/*report error parameters*/
		error = TRUE;
	}
	else
	{

	}

	if (FALSE == error)
	{
		/*get port address address*/
		switch (Dio_configuredPorts[PortId])
		{
		case 0: pin_ptr = &PORTA ;
		break ;
		case 1: pin_ptr = &PORTB ;
		break;
		case 2: pin_ptr = &PORTC;
		break ;
		case 3: pin_ptr = &PORTD;
		break ;
        case 4: pin_ptr = &PORTE;
		break ;
		}
		portLevel = *pin_ptr ;
		
	}
	else
	{
        
	}
return portLevel ;
}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level) {
volatile	uint8 *port_ptr = NULL_PTR;
	boolean error = FALSE;

	if (DIO_NOT_INITIALIZED == Dio_status)
	{
		/* report DIO not INITIALIZED  error */
		error = TRUE;

	}
	else
	{
		/* no action required */
	}
	if (DIO_CONFIGURED_CHANNELS <= ChannelId)
	{
		/*report error parameters*/
		error = TRUE;

	}
	else
	{

	}

	if (FALSE == error)
	{
		/*get port address address*/
		switch (Dio_configuredChannels[ChannelId].port_number)
		{
		case 0: port_ptr = &PORTA ;
		break ;
		case 1: port_ptr = &PORTB ;
		break;
		case 2: port_ptr = &PORTC;
		break ;
		case 3: port_ptr = &PORTD;
		break ;
        case 4: port_ptr = &PORTE;
		break ;
		}
		if (STD_LOW == Level)
		{
			CLR_BIT(*port_ptr,Dio_configuredChannels[ChannelId].channel_number);
		}
		else if (STD_HIGH == Level)
		{
			SET_BIT(*port_ptr,Dio_configuredChannels[ChannelId].channel_number);

		}
		else
		{

		}
	}
	else
	{
	}

}
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
volatile	uint8 *pin_ptr = NULL_PTR;
	Dio_LevelType ChannelLevel;
	boolean error = FALSE;

	if (DIO_NOT_INITIALIZED == Dio_status)
	{
		/* report DIO not INITIALIZED  error */
		error = TRUE;
	}
	else
	{
		/* no action required */
	}
	if (DIO_CONFIGURED_CHANNELS <= ChannelId)
	{
		/*report error parameters*/
		error = TRUE;
	}
	else
	{

	}

	if (FALSE == error) {
		/*get port address address*/
		switch (Dio_configuredChannels[ChannelId].port_number) {
		case 0: pin_ptr = &PORTA ;
		break ;
		case 1: pin_ptr = &PORTB ;
		break;
		case 2: pin_ptr = &PORTC;
		break ;
		case 3: pin_ptr = &PORTD;
		break ;
        case 4: pin_ptr = &PORTE;
		break ;
		}
		ChannelLevel = READ_BIT(*pin_ptr,Dio_configuredChannels[ChannelId].channel_number);
		
	}
	else
	{
	}
    return ChannelLevel;
}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId){

volatile	uint8 *pin_ptr = NULL_PTR;
volatile	uint8 *port_ptr = NULL_PTR;
	Dio_LevelType ChannelLevel;
	boolean error = FALSE;

	if (DIO_NOT_INITIALIZED == Dio_status)
	{
		/* report DIO not INITIALIZED  error */
		error = TRUE;
	}
	else
	{
		/* no action required */
	}
	if (DIO_CONFIGURED_CHANNELS <= ChannelId)
	{
		/*report error parameters*/
		error = TRUE;
	}
	else
	{

	}

	if (FALSE == error)
	{
		/*get port address address*/
		switch (Dio_configuredChannels[ChannelId].port_number)
		{

		case 0:pin_ptr = &PORTA;
			   port_ptr = &PORTA;
		break;

		case 1:pin_ptr = &PORTB;
			   port_ptr = &PORTB;
		break;

		case 2:pin_ptr = &PORTC;
			   port_ptr = &PORTC;
		break;

		case 3:pin_ptr = &PORTD;
			   port_ptr = &PORTD;
		break;
        case 4:pin_ptr = &PORTE;
			   port_ptr = &PORTE;
		break;
        
		}
		/* Read the required channel and write the required level */
		if(BIT_IS_SET(*pin_ptr,Dio_configuredChannels[ChannelId].channel_number))
		{
			CLR_BIT(*port_ptr,Dio_configuredChannels[ChannelId].channel_number);
			ChannelLevel = STD_LOW;
		}
		else if (BIT_IS_CLEAR(*pin_ptr,Dio_configuredChannels[ChannelId].channel_number))
		{
			SET_BIT(*port_ptr,Dio_configuredChannels[ChannelId].channel_number);
			ChannelLevel = STD_HIGH;
		}
		else
		{

		}
	
	}
	else
	{

	}
	return ChannelLevel;
}
