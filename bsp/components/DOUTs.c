#include "DOUTs.h"
#include "gpio.h"

static int init_callback(void){

    //uC pins init
    MX_GPIO_Init();
    return 0;
}

DigitalOutputs_t DOUTs={
.Init = &init_callback
};