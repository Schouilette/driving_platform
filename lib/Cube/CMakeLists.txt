set(sources_SRCS
    # Put here your source files, one in each line, relative to CMakeLists.txt file location
    ${PROJ_PATH}/lib/Cube/Core/Src/freertos.c
    ${PROJ_PATH}/lib/Cube/Core/Src/gpio.c
    ${PROJ_PATH}/lib/Cube/Core/Src/i2c.c
    ${PROJ_PATH}/lib/Cube/Core/Src/sdio.c
    ${PROJ_PATH}/lib/Cube/Core/Src/spi.c
    ${PROJ_PATH}/lib/Cube/Core/Src/tim.c
    ${PROJ_PATH}/lib/Cube/Core/Src/usart.c
    ${PROJ_PATH}/lib/Cube/Core/Src/stm32f4xx_hal_msp.c
    ${PROJ_PATH}/lib/Cube/Core/Src/stm32f4xx_hal_timebase_tim.c
    ${PROJ_PATH}/lib/Cube/Core/Src/stm32f4xx_it.c
    ${PROJ_PATH}/lib/Cube/Core/Src/system_stm32f4xx.c
    ${PROJ_PATH}/lib/Cube/startup_stm32f446xx.s
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c 
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c 
 #   ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c 
  #  ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.c 
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c 
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c 
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c 
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c 
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c 
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c 
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.c 
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.c 
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.c 
    ${PROJ_PATH}/lib/Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.c 

    ${PROJ_PATH}/lib/Cube/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.c
    ${PROJ_PATH}/lib/Cube/Middlewares/Third_Party/FreeRTOS/Source/timers.c
    ${PROJ_PATH}/lib/Cube/Middlewares/Third_Party/FreeRTOS/Source/tasks.c
    ${PROJ_PATH}/lib/Cube/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c
    ${PROJ_PATH}/lib/Cube/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c
    ${PROJ_PATH}/lib/Cube/Middlewares/Third_Party/FreeRTOS/Source/queue.c
    ${PROJ_PATH}/lib/Cube/Middlewares/Third_Party/FreeRTOS/Source/list.c
    ${PROJ_PATH}/lib/Cube/Middlewares/Third_Party/FreeRTOS/Source/croutine.c
    ${PROJ_PATH}/lib/Cube/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c
    ${PROJ_PATH}/lib/Cube/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c

 #   ${PROJ_PATH}/lib/Cube/USB_DEVICE/App/usb_device.c
 #   ${PROJ_PATH}/lib/Cube/USB_DEVICE/App/usbd_cdc_if.c
 #   ${PROJ_PATH}/lib/Cube/USB_DEVICE/App/usbd_desc.c
 #   ${PROJ_PATH}/lib/Cube/USB_DEVICE/Target/usbd_conf.c
)

MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

HEADER_DIRECTORIES(header_dir_list)
list(LENGTH header_dir_list header_dir_list_count)
message(STATUS "[INFO] Found ${header_dir_list} header directories.")
target_include_directories(${EXECUTABLE} PRIVATE ${header_dir_list}) 

target_sources(${EXECUTABLE} PRIVATE ${sources_SRCS})
