/**
  ******************************************************************************
  * @file    DINs.h
  * @brief   This file contains all the function prototypes for
  *          the DINs.c file
  ******************************************************************************
*/
#ifndef __DINs_H__
#define __DINs_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct 
{
  int (*Init)(void);
} DigitalInputs_t;


extern DigitalInputs_t DINs;
#ifdef __cplusplus
}
#endif
#endif
