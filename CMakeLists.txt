cmake_minimum_required(VERSION 3.18)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_language(C ASM)
set(PROJ_PATH                       ${CMAKE_CURRENT_SOURCE_DIR})
message("Build type: "              ${CMAKE_BUILD_TYPE})
project(robot-platform)

# https://github.com/MaJerle/stm32-cube-cmake-vscode
# Core MCU flags, CPU, instruction set and FPU setup
# Needs to be set properly for your MCU
#
set(CPU_PARAMETERS
    -mthumb
    # This needs attention to properly set for used MCU
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
)

# Set linker script
set(linker_script_SRC               ${PROJ_PATH}/lib/Cube/STM32F446RETx_FLASH.ld)
set(EXECUTABLE                      ${CMAKE_PROJECT_NAME}.elf)


    
# Symbols definition
set(symbols_SYMB
    # Put here your symbols (preprocessor defines), one in each line
    # Encapsulate them with double quotes for safety purpose
    "DEBUG"
    "STM32F466xx"
    "USE_FULL_LL_DRIVER"
    "HSE_VALUE=25000000"
    "USE_HAL_DRIVER"
)

# Executable files
add_executable(${EXECUTABLE} ${PROJ_PATH}/app/main.c ${PROJ_PATH}/app/main.h) 

# Include paths
add_subdirectory(${PROJ_PATH}/app)
add_subdirectory(${PROJ_PATH}/lib)
add_subdirectory(${PROJ_PATH}/bsp)


# Project symbols
target_compile_definitions(${EXECUTABLE} PRIVATE ${symbols_SYMB})

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    add_compile_definitions(DEBUG_PRINT)
endif()


# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
    ${CPU_PARAMETERS}
    -Wall
    -Wextra
    -Wpedantic
    -Wno-unused-parameter
    # Full debug configuration
    -Og -g3 -ggdb
)

# Linker options
target_link_options(${EXECUTABLE} PRIVATE
    -T${linker_script_SRC}
    ${CPU_PARAMETERS}
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map
    --specs=nosys.specs
    -u _printf_float                # STDIO float formatting support
    -Wl,--start-group
    -lc
    -lm
    -lstdc++
    -lsupc++
    -Wl,--end-group
    -Wl,--print-memory-usage
)

set(CPPCHECK_CONFIG
  "-D__GNUC__ "
  "-D__VFP_FP__ "
  "--enable=all"
  "--inconclusive" 
  "--inline-suppr"
  "--std=c11"
  "--output-file=cppcheck.txt"
)



if(CMAKE_BUILD_TYPE MATCHES "Static")
    find_program(CMAKE_C_CPPCHECK NAMES cppcheck)
    if (CMAKE_C_CPPCHECK)
        message(STATUS "cppcheck                 ${cppcheck}")
        list(APPEND CMAKE_C_CPPCHECK ${CPPCHECK_CONFIG})
        message(STATUS "CMAKE_C_CPPCHECK: ${CMAKE_C_CPPCHECK}")
    endif()
endif()



# Execute post-build to print size
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXECUTABLE}>
)

#Convert output to hex and binary
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${EXECUTABLE}> ${CMAKE_PROJECT_NAME}.hex
)

# Convert to bin file -> add conditional check?
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE}> ${CMAKE_PROJECT_NAME}.bin
)

