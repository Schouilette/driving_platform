/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @author Copyright 2024: Schouilette
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/

#include <main.h>
#include "HW_api.h"
#include "config.h"
#include "rtos.h"
#include "usart.h"

void HelloWorldTask(void *argument);
xTaskHandle HelloWorldTaskHandle;

/** The application entry point
 * @retval int
 */
int main(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  /* Initialize all configured peripherals */
  Init_Hardware(&HW);

  /* Create the thread(s) */
  xTaskCreate(HelloWorldTask, "Hello", 128*4, NULL, 24, &HelloWorldTaskHandle);

  /* Start scheduler */
  vTaskStartScheduler(); /* Call start function for freertos objects (in freertos.c) */
  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  while (1)
  {
  }
}

void HelloWorldTask(void *argument)
{
  for(;;)
  {
    HW.Toogle_output(Hb_Led);
    vTaskDelay(100);
    HW.Toogle_output(Led_D4);
    HAL_UART_Transmit(&huart1,(uint8_t *)"Hello world \r\n",sizeof("Hello world \r\n"),100);
  }
  vTaskDelete(NULL);
}
