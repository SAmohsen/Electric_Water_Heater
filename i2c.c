
#include "i2c.h"


static Port_Config g_SCL_config ; 
static Port_Config g_SDA_config ; 


void I2c_setConfigurations(void)
{
    g_SCL_config.port = SCL_PORT ; 
    g_SCL_config.pin_num = SCL_CHANNEL ; 
    g_SCL_config.direction = SCL_DIRECTION ; 
    
    g_SDA_config.port = SDA_PORT ; 
    g_SDA_config.pin_num = SDA_CHANNEL ; 
    g_SDA_config.direction = SDA_DIRECTION ; 
    
}

static void i2c_WaitForIdle(void)
{
    while ( (SEN == 1) || (RSEN == 1) || (PEN == 1) || (RCEN == 1) || (R_W == 1) );
    /* wait till I2C module completes previous operation and becomes idle */
}								


static void i2c_Ack(void)
{
	ACKDT = 0;            /* Acknowledge data bit, 0 = ACK */
	ACKEN = 1;            /* Ack data enabled */
	while(ACKEN == 1);    /* wait for ack data to send on bus */
}

static void i2c_NoAck(void)
{
	ACKDT = 1;            /* Acknowledge data bit, 1 = NAK/NoAK */
	ACKEN = 1;            /* Ack data enabled */
	while(ACKEN == 1);    /* wait for ack data to send on bus */
}


void I2C_Init(void)
{
    I2c_setConfigurations() ; 
	SSPSTAT |= 0x80;  /* Slew rate disabled */
	SSPCON = 0x28;    /* SSPEN = 1, I2C Master mode, clock = FOSC/(4 * (SSPADD + 1)) */
	SSPADD = 50;      /* 100Khz @ 20Mhz Fosc */
}

void I2C_Restart(void)
{
	RSEN = 1;        /* Repeated start enabled */
	while(RSEN);     /* wait for condition to finish */
}

void I2C_Start(void)
{
	SEN = 1;              /* trigger the Start condition and wait till its completed*/
	while(SEN == 1);      /* automatically cleared by hardware once start condition is completed */

}
void I2C_Stop(void)
{
	PEN = 1;              /* Trigger stop condition, Wait till stop condition to finished*/
	while(PEN == 1);      /* PEN automatically cleared by hardware once stop condition is finished*/
}


void I2C_Write(uint8 v_i2cData_u8)
{

    SSPBUF = v_i2cData_u8;  /* Copy the data to be transmitted into SSPBUF */
    while(BF==1);             /* wait till the data is transmitted */
    i2c_WaitForIdle();        /* wait till current operation is complete*/
}


uint8 I2C_Read(uint8 v_ackOption_u8)
{
	uint8  v_i2cData_u8=0x00;

	RCEN = 1;                   /* Enable data reception */
	while(BF==0);               /* wait for data to be received */
	v_i2cData_u8 = SSPBUF;    /* copy the received data */
	i2c_WaitForIdle();          /* wait till current operation is complete*/
	      
	if(v_ackOption_u8==1)     /*Send the Ack/NoAck depending on the user option*/
	{
		i2c_Ack();
	}
	else
	{
		i2c_NoAck();
	}

	return v_i2cData_u8;       /* Finally return the received Byte */
}