/**
  ******************************************************************************
  * @file    HW_api.h
  * @brief   This file contains all the function prototypes for
  *          hardware componets
  ******************************************************************************
*/
#ifndef __HW_API_H__
#define __HW_API_H__

#ifdef __cplusplus
extern "C" {
#endif

//#include "Digital_IOs.h"
#include "stm32f4xx_hal.h"
#include "config.h"
typedef struct {
    HAL_StatusTypeDef (*Set_output)(uint8_t name, uint8_t state);
    HAL_StatusTypeDef (*Toogle_output)(uint8_t name);
    GPIO_PinState (*Get_IO_value)(uint8_t name);
    int variable;
}Hardware_t;



HAL_StatusTypeDef Init_Hardware(Hardware_t *HW);


extern Hardware_t HW;
#ifdef __cplusplus
}
#endif
#endif 