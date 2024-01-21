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
        
        MX_I2C1_Init();
        MX_SPI1_Init();
        MCP23017_init(&MCP_expander_1, &hi2c1, MCP23017_ADDRESS);

        return HAL_OK;
    }
    return HAL_ERROR;
}


Hardware_t HW = {
    .DINs = &DINs,
    .DOUTs = &DOUTs,
    .variable = 10
};





