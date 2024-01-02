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

#include "DINs.h"

typedef struct 
{
  DigitalInputs_t* DINs;
  int variable;
} Hardware_t;


extern Hardware_t HW;
#ifdef __cplusplus
}
#endif
#endif