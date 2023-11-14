cmake_minimum_required(VERSION 3.18)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
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


# List of source files to compile
# Include directories

#MACRO(HEADER_DIRECTORIES return_list)
 #   FILE(GLOB_RECURSE new_list *.h)
  #  SET(dir_list "")
   # FOREACH(file_path ${new_list})
    #    GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
     #   SET(dir_list ${dir_list} ${dir_path})
    #ENDFOREACH()
    #LIST(REMOVE_DUPLICATES dir_list)
    #SET(${return_list} ${dir_list})
#ENDMACRO()

#HEADER_DIRECTORIES(header_dir_list)

#list(LENGTH header_dir_list header_dir_list_count)
#message(STATUS "[INFO] Found ${header_dir_list_count} header directories.")
#target_include_directories(${EXECUTABLE} PRIVATE 
#${header_dir_list})
# ${include_path_DIRS})

    
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


# Project symbols
target_compile_definitions(${EXECUTABLE} PRIVATE ${symbols_SYMB})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
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

