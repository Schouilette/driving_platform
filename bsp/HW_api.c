#include "HW_api.h"
#include <stddef.h>
#include "MCP23017.h"
#include "spi.h"
#include "i2c.h"
#include "Digital_IOs.h"


HAL_StatusTypeDef Init_Hardware(Hardware_t *HW){
    if (HW != NULL){
        MX_I2C1_Init();
        MX_SPI1_Init();
       
        HAL_Delay(5);
        DINS_init();
       
        return HAL_OK;
    }
    return HAL_ERROR;
}


Hardware_t HW = {
    .variable = 10,
    .Set_output = &__Set_output,
    .Toogle_output = &__Toogle_output,
    .Get_IO_value = &__Get_io_val
};





