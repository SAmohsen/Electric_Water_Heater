
#include "external_eeprom.h"

void externalEEPROM_init (void)
{
    I2C_Init();
}
void externalEEPROM_writeU8Data (uint8 Data, uint8 Addr)
{
    I2C_Start();
    I2C_Write(EEPROM_ADDRESS_WRITE_OPERATION);
    I2C_Write(Addr);
    I2C_Write(Data);
    I2C_Stop();
}

void externalEEPROM_readU8Data (uint8* Data, uint8 Addr)
{
    I2C_Start();
    I2C_Write(EEPROM_ADD_READ_OPERATION);
    I2C_Write(Addr);
    I2C_Restart();
    I2C_Write(EEPROM_ADD_READ_OPERATION);
    *Data = I2C_Read(1);
    I2C_Stop();
}

