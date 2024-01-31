#include "HW_api.h"
#include <stddef.h>
#include "MCP23017.h"
#include "spi.h"
#include "i2c.h"

MCP23017 MCP_expander_1;



HAL_StatusTypeDef Init_Hardware(Hardware_t *HW){
    if (HW != NULL){
        HW->DINs= &DINs;
        HW->DOUTs= &DOUTs;
        HW->variable = 10;

        HW->DINs->Init();
        
        MX_I2C1_Init();
        MX_SPI1_Init();
        MCP23017_init(&MCP_expander_1, &hi2c1, MCP23017_ADDRESS);

        //PORTA set as outputs and PORTB set as inputs
        uint8_t port_a_dir = MCP23017_IODIR_ALL_OUTPUT;
        uint8_t port_b_dir = MCP23017_IODIR_ALL_INPUT;
        MCP23017_set_all_pins_dir(&MCP_expander_1,port_a_dir+ (port_b_dir<<8));

        HAL_Delay(5);
       
        return HAL_OK;
    }
    return HAL_ERROR;
}

HAL_StatusTypeDef Set_LEd( uint8_t pin, uint8_t state){
    if (&MCP_expander_1 != NULL){
        return MCP23017_set_pin(&MCP_expander_1,  pin, state);
    }
    return HAL_ERROR;
}

Hardware_t HW = {
    .DINs = &DINs,
    .DOUTs = &DOUTs,
    .variable = 10
};





