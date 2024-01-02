
#include "DINs.h"
#include "gpio.h"

static int init_callback(void){

    //uC pins init
    MX_GPIO_Init();
    return 0;
}

DigitalInputs_t DINs={
.Init = &init_callback
};
