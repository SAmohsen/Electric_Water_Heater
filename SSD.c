/*
 * SSD.c
 *
 *  Created on: Dec 14, 2019
 *      Author: sayed
 */

#include "SSD.h"
#include "Port.h"
#include "DIO.h"


#define SSD_setValue(value) (Dio_WritePort(DioConf_SSD_PORT_INDEX,g_SSD_DataArr[value]))
#define Disp_Off     (SEVEN_SEGMENT_ENABLE_PORT &= 0xCF )

static uint8 g_SSD_DataArr[10] = {
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111,
};

static Port_ConfigPort g_SSD_DataPortConfig;
static Port_Config g_SSD_DISP1_Enable_config;
static Port_Config g_SSD_DISP2_Enable_config;

static void SSD_setConfigurations() {
    g_SSD_DataPortConfig.port = SSD_DATA_PORT;
    g_SSD_DataPortConfig.direction = SSD_DATA_PORT_DIR;

    g_SSD_DISP1_Enable_config.port = SSD_DISP1_ENABLE_PORT;
    g_SSD_DISP1_Enable_config.pin_num = SSD_DISP1_ENABLE_CHANNEL_NUMBER;
    g_SSD_DISP1_Enable_config.direction = SSD_DISP1_ENABLE_DIR;

    g_SSD_DISP2_Enable_config.port = SSD_DISP2_ENABLE_PORT;
    g_SSD_DISP2_Enable_config.pin_num = SSD_DISP2_ENABLE_CHANNEL_NUMBER;
    g_SSD_DISP2_Enable_config.direction = SSD_DISP2_ENABLE_DIR;


}

void Disp_init() {
    SSD_setConfigurations();
    Port_SetPortDirection(&g_SSD_DataPortConfig);
    Port_SetDirection(&g_SSD_DISP1_Enable_config);
    Port_SetDirection(&g_SSD_DISP2_Enable_config);

}

void Disp_updateValue(uint8 value) {
    SSD_setValue(value / 10);
    SEVEN_SEGMENT_ENABLE_PORT |= (1 << SEVENSEGMENT1_ENABLE);
    __delay_ms(5);
    SEVEN_SEGMENT_ENABLE_PORT &= ~(1 << SEVENSEGMENT1_ENABLE);
    SSD_setValue(value % 10);
    SEVEN_SEGMENT_ENABLE_PORT |= (1 << SEVENSEGMENT2_ENABLE);
    __delay_ms(5);
    SEVEN_SEGMENT_ENABLE_PORT &= ~(1 << SEVENSEGMENT2_ENABLE);
}

void Disp_turnDiplaysOff() {
    Disp_Off;
}


void Disp_updateValue_blink(uint8 value) {
static uint16 blink = 0;
    blink++;
    if (blink < 100) {

        Disp_updateValue(value);
    } else if (blink < 200) {

        Disp_turnDiplaysOff();
    } else {
        blink = 0;
    }

}