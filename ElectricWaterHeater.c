/******************************************************************************
 *
 * Module: EWH
 *
 * File Name: Eelectrical Water Heater.c
 *
 * Description: Source file For Electrical WAter Heater System
 *
 * Author: sayed mohsen
 *
 *******************************************************************************/


#include "ElectricWaterHeater.h"



/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/
Heater_states g_curr_heater_state = OFF_STATE; /*global Variable To Hold Current Heater State*/

/*global Structure To Hold Temperature Setting*/
EWH_TempSettingsType EWH_TempSettings = {
    .g_Curr_temp_readings = 0,
    .g_avg_waterTemp = 0,
    .g_curr_waterTemp = 0,
    .g_required_Temp = 0
};

/*global Structure To Hold Periodic Tasks Times*/
EWH_SysTimesType EWH_SysTimes = {
    .lastpressedswTime = 0,
    .tempsensingTime = 0,
};

/*global bit field To Hold System Flags*/
EWH_SysFlagsType EWH_SysFlags = {
    .SW_pressed_flag = 0,
    .SW_time_flag = 0,
    .display_time_flag = 0,
    .led_time_flag = 0,
    .temp_sensing_time_flag = 0,
    .pressed_Sw_timeout = 0
};

/************************************************************************************
 * Task Name: SW_Task
 * Description: -Periodic Task to update Switch Samples and Update Switch States.
 *              -Switch Samples should be update once every 5 ms
 ************************************************************************************/
void SW_Task() {
    SW_updateSamples();
    if (SW_UpdateStates()) /*Check if There is Any Pressed Switch */ {
        if ((SW_getState(DioConf_HEATER_POWER_SW_INDEX) == SW_PRESSED)) {
            /*  If the ON/OFF button is released and the electric water heater is in ON
             state, the electric water heater goes to OFF state */

            if ((g_curr_heater_state == TIME_SETTING_STATE) || (g_curr_heater_state == TEMP_CONTROLLING_STATE)) {
                g_curr_heater_state = OFF_STATE;
            } else {
                /*
                 *If the ON/OFF button is Pressed and the electric water heater is in OFF
                 *state, the electric water heater goes to ON state 
                 */
                g_curr_heater_state = TEMP_CONTROLLING_STATE;
            }
        }
        else if ((SW_getState(DioConf_UP_TEMPERATURE_SW_INDEX) == SW_PRESSED) || (SW_getState(DioConf_DOWN_TEMPERATURE_SW_INDEX) == SW_PRESSED)) {
            g_curr_heater_state = TIME_SETTING_STATE;
        }

    }
}

/************************************************************************************
 * Task Name: TempSensing_Task
 * Description:  -Periodic Task to Update current Water Temperature based On 
 *                   Required Number OF Temp Readings Sample .
 *               -Temperature should be sensed once every 100 ms
 ************************************************************************************/
void TempSensing_Task() {
    EWH_TempSettings.g_curr_waterTemp = EWH_TempSettings.g_curr_waterTemp + LM35_ReadTemp();
    EWH_TempSettings.g_Curr_temp_readings++;
    if (EWH_TempSettings.g_Curr_temp_readings == NO_WATER_TEMPERATURE_READINGS) {

        /*    
         * The decision to turn ON or OFF either the ?Heating Element? or the
         * Cooling Element? based on the average of the last 10 temperature readings
         **/
        EWH_TempSettings. g_avg_waterTemp = (EWH_TempSettings.g_curr_waterTemp / NO_WATER_TEMPERATURE_READINGS);

        /*rest Current Temperature Readings*/
        EWH_TempSettings. g_curr_waterTemp = 0;
        EWH_TempSettings.g_Curr_temp_readings = 0;
    }
}

/************************************************************************************
 * Task Name: Display_Task
 * Description:  -Periodic Task to Update Seven Segment Display .
 *               -Display should be updated  once every 5 ms.
 ************************************************************************************/
void Display_Task(void) {
    /*In the OFF state, all display should be turned OFF*/
    if (g_curr_heater_state == OFF_STATE) {
        Disp_turnDiplaysOff();
    }/*In the temperature setting mode, every change in the set temperature
         * should be reflected on the 2 seven segment displays*/
    else if (g_curr_heater_state == TIME_SETTING_STATE) {
        Disp_updateValue_blink(EWH_TempSettings.g_required_Temp);
    }/*By default, the 2 seven segment display are show the current water temperature*/
    else {
        Disp_updateValue(EWH_TempSettings.g_avg_waterTemp);
    }
}

void Active_Task(void) {
    if (g_curr_heater_state == TIME_SETTING_STATE) {
        /*The ?External E2PROM? should save the set temperature once set */
        externalEEPROM_writeU8Data(EWH_TempSettings.g_required_Temp, EEPROM_REQUIRED_TEMP_ADDR);
        g_curr_heater_state = TEMP_CONTROLLING_STATE;
    }
}

/************************************************************************************
 * Service Name: TempControl_State
 * Parameters (in): None
 * Return value:None
 * Description: Function to Start Controlling Water Temperature.
 ************************************************************************************/
void TempControl_State(void) {
    if ((EWH_TempSettings.g_avg_waterTemp >= (EWH_TempSettings.g_required_Temp + TEMPERATURE_ERROR_BASE))) {

        /*The ?Heating Element? should be turned OFF, if the current water
            temperature is greater than the set temperature by 5 degrees*/
        Heater_Off();

        /* The ?Cooling Element? should be turned ON, if the current water
            temperature is greater than the set temperature by 5 degrees*/
        Fan_On();
    }

   if ((EWH_TempSettings.g_avg_waterTemp <= (EWH_TempSettings.g_required_Temp - TEMPERATURE_ERROR_BASE))) {
        /*  The ?Cooling Element? should be turned OFF, if the current water
                temperature is less than the set temperature by 5 degrees*/
        Fan_Off();

        /*The ?Heating Element? should be turned ON, if the current water
            temperature is less than the set temperature by 5 degrees */
        Heater_On();
    }
}

/************************************************************************************
 * Service Name: TempSetting_State
 * Parameters (in): None
 * Return value:None
 * Description: Function to Set Required Water Temperature.
 ************************************************************************************/
void TempSetting_State() {
    SW_updateSamples();

    /*After entering temperature setting mode, a single ?Up? 
     * button press increase the set temperature by 5 degrees*/
    if (SW_getState(DioConf_UP_TEMPERATURE_SW_INDEX) == SW_PRESSED) {
        /*The maximum possible set temperature is 75 degrees*/
        if (EWH_TempSettings.g_required_Temp < MAX_TEMPERATURE_SET) {
            EWH_TempSettings.g_required_Temp = EWH_TempSettings.g_required_Temp + TEMPERATURE_BASE;
            EWH_SysFlags.SW_pressed_flag = 1;
        }
    }/*After entering temperature setting mode, a single ?Down? 
         * button press decrease the set temperature by 5 degrees*/
    else if (SW_getState(DioConf_DOWN_TEMPERATURE_SW_INDEX) == SW_PRESSED) {
        /*The minimum possible set temperature is 35 degrees*/
        if (EWH_TempSettings.g_required_Temp > MINI_TEMPERATURE_SET) {
            EWH_TempSettings.g_required_Temp = EWH_TempSettings.g_required_Temp - TEMPERATURE_BASE;

            EWH_SysFlags.SW_pressed_flag = 1;
        }
    } else {
        EWH_SysFlags.SW_pressed_flag = 0;
    }
}

/************************************************************************************
 * Service Name: EWH_updateState
 * Parameters (in): None
 * Return value:None
 * Description: Function to update Operating Mode  Electrical Water Heater System.
 ************************************************************************************/
void EWH_updateState() {
    switch (g_curr_heater_state) {
        case OFF_STATE:
            Fan_Off();
            Heater_Off();
            break;
        case TIME_SETTING_STATE:
            Fan_Off();
            Heater_Off();
            //  ON_Task() ; 
            TempSetting_State();
            break;
        case TEMP_CONTROLLING_STATE:
            TempControl_State();
            break;
    }
}

/************************************************************************************
 * Service Name: EWH_initTask
 * Parameters (in): None
 * Return value:None
 * Description: Function to Initialize Electrical Water Heater System.
 ************************************************************************************/
void EWH_initTask() {
    /* Initialize Dio Driver */
    Dio_Init(&DIO_configuration);

    /* Initialize ADC Driver */
    Adc_init(&Adc_configuration);

    /*Initialize External HardWare Modules*/
    Fan_init();
    Heater_init();
    LM35_Init();
    SW_init();
    Disp_init();
    LED_init();
    externalEEPROM_init();
    externalEEPROM_writeU8Data(HEATER_INITIAL_TEMPERATURE,EEPROM_REQUIRED_TEMP_ADDR); /*The initial set temperature is 60 degrees */
          
    /*  If the electric water heater is turned OFF then ON, the stored set
             * temperature should be retrieved from the ?External E2PROM? */
    //     externalEEPROM_readU8Data(&EWH_TempSettings.g_required_Temp, EEPROM_REQUIRED_TEMP_ADDR);
      EWH_TempSettings.g_required_Temp =  HEATER_INITIAL_TEMPERATURE  ;
    EWH_TempSettings.g_avg_waterTemp = LM35_ReadTemp();
}




