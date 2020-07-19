 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for  ADC driver
 *
 * Author: sayed mohsen
 *
 *******************************************************************************/


#include "ADC.h"


static uint8 Adc_Status = ADC_NOT_INITIALIZED ;/*static global variable for ADC status */

/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

void Adc_init(const Adc_ConfigType *Config_Ptr) {
	if (NULL_PTR != Config_Ptr) {
	//	ADCON0 &= ~(1 << 0) ; /*Turn oFF ADC  */  
		/*set ADC prescale value ADC must operate in range 50-200Khz*/
        ADCON0 = (ADCON0 & 0xCF) | ((Config_Ptr->prescale & 0x03)<<6);
        ADCON1 = (ADCON1 & 0xBF) | ((Config_Ptr->prescale & 0x04)<<4);
        
        switch (Config_Ptr->aligment)/*ADC result Alignment*/
		{
		case ADC_ALIGN_LEFT:CLR_BIT(ADCON1,7);
		break;
		case ADC_ALIGN_RIGHT:SET_BIT(ADCON1,7);
		break;
		}
   
		Adc_Status = ADC_INITIALIZED;
	}
}

Adc_ValueGroupType Adc_readChannel(Adc_Channel channel) {
    Adc_ValueGroupType Adc_result = 0;
    if (ADC_INITIALIZED == Adc_Status) {
        ADCON0 |= (1 << 0) ; /*Turn on ADC  */ 
        ADCON0 = (ADCON0 & 0xC7) | ((channel & 0x07) << 3); /*set correct channel*/
        __delay_ms(3);//delay Required After Setting Channel
        SET_BIT(ADCON0, 2); /*start conversion set go /Done bit*/
        while (BIT_IS_SET(ADCON0, 2)); /*wait until ADC Finish Conversion go/done = 0*/
       /* ADC Flag Cleared Automatically*/
        ADCON0 &= ~(1 << 0) ; /*Turn oFF ADC  */ 
        Adc_result =(ADRESH<<8) +  ADRESL ;     
    }
    
    return Adc_result;
}

