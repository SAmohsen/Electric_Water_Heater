/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: Header file for the ADC driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/


#ifndef ADC_ADC_H_
#define ADC_ADC_H_

#include "std_types.h"
#include "common_marcos.h"
#include  "micro_config.h"




/*
 * Macros for ADC Status
 */
#define ADC_INITIALIZED                (1U)
#define ADC_NOT_INITIALIZED            (0U)

/*number of ADC channels */
#define NUMBER_ADC_CHANNELS (7U)

/*ADC Auto Triggering Mode*/
#define ADC_AUTO_TRIGGERING_MODE (STD_OFF)
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

typedef uint16 Adc_ValueGroupType; /*type to hold ADC result*/

typedef enum {
    ADC_ALIGN_LEFT,
    ADC_ALIGN_RIGHT
} Adc_ResultAlignmentType; /*type For ADC Result Alignment*/

typedef enum {
    Adc_channel0,
    Adc_channel1,
    Adc_channel2,
    Adc_channel3,
    Adc_channel4,
    Adc_channel5,
    Adc_channel6,
    Adc_channel7,
} Adc_Channel; /*type for ADC Channels */


typedef enum {
    Adc_Prescale_2,
    Adc_Prescale_8,
    Adc_Prescale_32,
    Adc_prescale_internal_RC,
    Adc_Prescale_4,
    Adc_Prescale_16,
    Adc_Prescale_64,
    Adc_Prescale_128
} Adc_PrescaleType; /*type For ADC Clock*/

typedef struct {
    Adc_PrescaleType prescale;
    Adc_ResultAlignmentType aligment;
} Adc_ConfigType; /*Type For ADC Configuration*/

/**************************************************************************************
 * 							Function ProtoTypes
 * ************************************************************************************/

void Adc_init(const Adc_ConfigType *Config_Ptr);
Adc_ValueGroupType Adc_readChannel(Adc_Channel channel);
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern const Adc_ConfigType Adc_configuration;

#endif /* ADC_ADC_H_ */
