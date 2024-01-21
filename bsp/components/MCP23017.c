#include    "MCP23017.h"
#include    "i2c.h"
#include    <stdlib.h>

// Registers
#define REGISTER_IODIRA		0x00
#define REGISTER_IODIRB		0x01
#define REGISTER_IPOLA		0x02
#define REGISTER_IPOLB		0x03
#define REGISTER_GPINTENA	0x04
#define REGISTER_GPINTENB	0x05
#define REGISTER_DEFVALA	0x06
#define REGISTER_DEFVALB	0x07
#define REGISTER_INTCONA	0x08
#define REGISTER_INTCONB	0x09
//	IOCON			0x0A
//	IOCON			0x0B
#define REGISTER_GPPUA		0x0C
#define REGISTER_GPPUB		0x0D
#define REGISTER_INTFA		0x0E
#define REGISTER_INTFB		0x0F
#define REGISTER_INTCAPA	0x10
#define REGISTER_INTCAPB	0x11
#define REGISTER_GPIOA		0x12
#define REGISTER_GPIOB		0x13
#define REGISTER_OLATA		0x14
#define REGISTER_OLATB		0x15


void MCP23017_deinit(MCP23017* mcp){

    free(mcp);
}


/**
 * @brief Sets the direction of all pins on the MCP23017.
 *
 * This function sets the direction of all pins on the MCP23017 to either input or output.
 *
 * @param mcp Pointer to the MCP23017 structure.
 * @param dir The direction to set for all pins. Each bit represents the direction of a pin, where 0 is input and 1 is output.
 * @return HAL_StatusTypeDef The status of the I2C memory write operation.
 */
HAL_StatusTypeDef MCP23017_set_all_pins_dir(MCP23017* mcp, uint16_t dir){

    mcp->iodir = dir;
    return HAL_I2C_Mem_Write(mcp->i2c, mcp->address, REGISTER_IODIRA, 2, (uint8_t*)&mcp->iodir, 2, 100);
}

/**
 * @brief Sets the direction of a pin on the MCP23017 GPIO expander.
 *
 * This function sets the direction of a specific pin on the MCP23017 GPIO expander.
 * The MCP23017 supports 16 pins, numbered from 0 to 15.
 *
 * @param mcp Pointer to the MCP23017 structure.
 * @param pin The pin number to set the direction for.
 * @param dir The direction to set for the pin. Use 0 for input and any non-zero value for output.
 *
 * @return HAL_StatusTypeDef The status of the operation. HAL_OK if successful, HAL_ERROR otherwise.
 */
HAL_StatusTypeDef MCP23017_set_pin_dir(MCP23017* mcp, uint16_t pin, uint16_t dir){

    if(pin > 15){
        return HAL_ERROR;
    }
    if(dir == 0){
        mcp->iodir |= (1<<pin);
    }else{
        mcp->iodir &= ~(1<<pin);
    }
    return HAL_I2C_Mem_Write(mcp->i2c, mcp->address, REGISTER_IODIRA, 2, (uint8_t*)&mcp->iodir, 2, 100);
}

/**
 * @brief Sets the value of all pins on the MCP23017.
 *
 * This function sets the value of all pins on the MCP23017 to either high or low.
 *
 * @param mcp Pointer to the MCP23017 structure.
 * @param value The value to set for all pins. Each bit represents the value of a pin, where 0 is low and 1 is high.
 * @return HAL_StatusTypeDef The status of the I2C memory write operation.
 */
HAL_StatusTypeDef MCP23017_set_all_pins(MCP23017* mcp, uint16_t value){

    mcp->gpio_value = value;
    return HAL_I2C_Mem_Write(mcp->i2c, mcp->address, REGISTER_GPIOA, 2, (uint8_t*)&mcp->gpio_value, 2, 100);
}

/**
 * @brief Sets the value of a pin on the MCP23017 GPIO expander.
 *
 * This function sets the value of a specific pin on the MCP23017 GPIO expander.
 *
 * @param mcp Pointer to the MCP23017 structure.
 * @param pin The pin number to set the value for (0-15).
 * @param value The value to set the pin to (0 or 1).
 * @return HAL_StatusTypeDef The status of the operation (HAL_OK or HAL_ERROR).
 */
HAL_StatusTypeDef MCP23017_set_pin(MCP23017* mcp, uint16_t pin, uint8_t value){

    if(pin > 15){
        return HAL_ERROR;
    }
    if(value == 0){
        mcp->gpio_value &= ~(1<<pin);
    }else{
        mcp->gpio_value |= (1<<pin);
    }
    return HAL_I2C_Mem_Write(mcp->i2c, mcp->address, REGISTER_GPIOA, 2, (uint8_t*)&mcp->gpio_value, 2, 100);
}

/**
 * @brief Gets the value of all pins on the MCP23017.
 *
 * This function gets the value of all pins on the MCP23017.
 *
 * @param mcp Pointer to the MCP23017 structure.
 * @return uint16_t The value of all pins. Each bit represents the value of a pin, where 0 is low and 1 is high.
 */
uint16_t MCP23017_get_all_pins_value(MCP23017* mcp){

    HAL_I2C_Mem_Read(mcp->i2c, mcp->address, REGISTER_GPIOA, 2, (uint8_t*)&mcp->gpio_value, 2, 100);
    return mcp->gpio_value;
}

/**
 * @brief Gets the value of a pin on the MCP23017 GPIO expander.
 *
 * This function gets the value of a specific pin on the MCP23017 GPIO expander.
 *
 * @param mcp Pointer to the MCP23017 structure.
 * @param pin The pin number to get the value for (0-15).
 * @return uint8_t The value of the pin (0 or 1).
 */
uint8_t MCP23017_get_pin_value(MCP23017* mcp, uint16_t pin){
 
    if(pin > 15){
        return 0;
    }
    HAL_I2C_Mem_Read(mcp->i2c, mcp->address, REGISTER_GPIOA, 2, (uint8_t*)&mcp->gpio_value, 2, 100);
    return (mcp->gpio_value>>pin)&0x01;
}



HAL_StatusTypeDef MCP23017_init(MCP23017* mcp, I2C_HandleTypeDef* i2c, uint8_t address){

    mcp->i2c = i2c;
    mcp->address = address<<1;
    mcp->iodir=0xFF;
    mcp->gpio_value = 0;
    //initialize device with all pins as inputs
    return HAL_I2C_Mem_Write(mcp->i2c, mcp->address, REGISTER_IODIRA, 1, (uint8_t*)&mcp->iodir, 1, 100);
}