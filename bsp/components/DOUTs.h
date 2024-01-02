/**
  ******************************************************************************
  * @file    DOUTs.h
  * @brief   This file contains all the function prototypes for
  *          the DOUTs.c file
  ******************************************************************************
*/
#ifndef __DOUTs_H__
#define __DOUTs_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct 
{
  int (*Init)(void);
} DigitalOutputs_t;


extern DigitalOutputs_t DOUTs;
#ifdef __cplusplus
}
#endif
#endif
