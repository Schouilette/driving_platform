#include "Digital_IOs.h"
#include "gpio.h"
#include <stdio.h>



static int DOUTs_init_callback(void){

    //MCU pins init
    //return MCP23017_  
    return 0;
}

DigitalOutputs_t DOUTs={
.Init = &DOUTs_init_callback
};

static int DINS_init_callback(void){

    //uC pins init
    MX_GPIO_Init();
    return 0;
}

static int _DINS_read_callback(MCP23017* mcp){

    //read mcp23017 expander
    return MCP23017_get_all_pins_value(mcp);

}

DigitalInputs_t DINs={
.Init = &DINS_init_callback,
.Read = &_DINS_read_callback
};



