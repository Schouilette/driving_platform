/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @author Copyright 2024: Schouilette
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/

// #include "gpio.h"

#include <cmsis_os2.h>
#include "tim.h"
#include "usart.h"
#include <main.h>
#include <HW_api.h>



/** The application entry point.
 * @retval int
 */
int main(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();


  /* Initialize all configured peripherals */
  Init_Hardware(&HW);

  MX_TIM2_Init();
  MX_TIM5_Init();
  MX_TIM8_Init();
  MX_USART1_UART_Init();

  /*FreeRTOS configuration*/
  /* Init scheduler */
  osKernelInitialize(); /* Call init function for freertos objects (in freertos.c) */
  
  /* Start scheduler */
  osKernelStart();
  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  while (1)
  {
  }
}


