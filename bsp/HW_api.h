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

#include "Digital_IOs.h"
#include "stm32f4xx_hal.h"
typedef struct {
    DigitalInputs_t *DINs;
    DigitalOutputs_t *DOUTs;
    int variable;
}Hardware_t;

HAL_StatusTypeDef Init_Hardware(Hardware_t *HW);
HAL_StatusTypeDef Set_LEd(uint8_t pin, uint8_t state);

extern Hardware_t HW;
#ifdef __cplusplus
}
#endif
#endif 