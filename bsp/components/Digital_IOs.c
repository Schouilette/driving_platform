#include "Digital_IOs.h"
#include "gpio.h"
#include "i2c.h"
#include <stdio.h>
#include "MCP23017.h"
#include "config.h"

MCP23017 MCP_expander_1;

typedef struct {
    IO_descriptor_t descriptor;
    IO_type_t type;
    uint8_t pin;
    uint8_t mode;
    uint8_t state;
} IO_t;

IO_t IO_config[] = {
    {Hb_Led, GPIO, 0, IO_MODE_OUTPUT, IO_LOW},
    {Pb_1, GPIO, 1, IO_MODE_INPUT, IO_LOW},
    {Pb_2, GPIO, 2, IO_MODE_INPUT, IO_LOW},
    {Sw_1, MCP23017_1, PORTB_OFFSET+0, IO_MODE_INPUT, IO_LOW},
    {Sw_2, MCP23017_1, PORTB_OFFSET+1, IO_MODE_INPUT, IO_LOW},
    {Sw_3, MCP23017_1, PORTB_OFFSET+2, IO_MODE_INPUT, IO_LOW},
    {Sw_4, MCP23017_1, PORTB_OFFSET+3, IO_MODE_INPUT, IO_LOW},
    {Sw_5, MCP23017_1, PORTB_OFFSET+4, IO_MODE_INPUT, IO_LOW},
    {Led_D3, MCP23017_1, PORTA_OFFSET+7, IO_MODE_OUTPUT, IO_LOW},
    {Led_D4, MCP23017_1, PORTA_OFFSET+6, IO_MODE_OUTPUT, IO_LOW},
    {Led_D5, MCP23017_1, PORTA_OFFSET+5, IO_MODE_OUTPUT, IO_LOW},
    {Led_D6, MCP23017_1, PORTA_OFFSET+4, IO_MODE_OUTPUT, IO_LOW},
    {Led_D7, MCP23017_1, PORTA_OFFSET+3, IO_MODE_OUTPUT, IO_LOW},
    {Led_D8, MCP23017_1, PORTA_OFFSET+2, IO_MODE_OUTPUT, IO_LOW}, 
};


/**
 * @brief Loads the MCP23017 pins configuration based on the specified IO type and configuration.
 *
 * This function iterates through the IO_config array and checks if the type is MCP23017_1 and the mode is IO_MODE_OUTPUT.
 * If both conditions are met, the corresponding pin is set in the dir variable with 1 value.
 *
 * @param type The IO type.
 * @param IO_config The IO configuration array.
 * @return The loaded MCP23017 pins configuration.
 */
uint16_t load_MCP23017_pins_config(IO_type_t type, IO_t* IO_config ){
    uint16_t dir = 0;
    for (uint8_t i = 0; i < sizeof(*IO_config)/sizeof(IO_t); i++) {
        if (IO_config[i].type == MCP23017_1 && IO_config[i].mode == IO_MODE_OUTPUT) {
            dir |= (1 << IO_config[i].pin);
        }
    }
    return dir;
}

void set_GPIO_output(uint8_t pin, uint8_t state) {
    switch (pin)
    {
    case 0://LED D1 
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, state);
        break;
    case 1: //PB1 io - not used now
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, state);
        break;
    case 2: //PB2 io- now used now
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, state);
        break;
    default:
        break;
    }
}

GPIO_PinState get_GPIO_input(uint8_t pin) {
    switch (pin)
    {
    case 0:// LED D1 
        return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15);
        break;
    case 1: //PB1 io - not used now
        return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13); 
        break;
    case 2: //PB2 io- now used now
        return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14);
        break;
    default:
        return -1;  //Error
        break;
    }
}

HAL_StatusTypeDef DINS_init(void) {
    // uC pins init
    MX_GPIO_Init();

    MCP23017_init(&MCP_expander_1, &hi2c1, MCP23017_ADDRESS);

    //PORTA set as outputs and PORTB set as inputs
    uint8_t dir= load_MCP23017_pins_config(MCP23017_1, IO_config);
    MCP23017_set_all_pins_dir(&MCP_expander_1,dir);
    return 0;
}

GPIO_PinState __Get_io_val(uint8_t name) {
    for (uint8_t i = 0; i < sizeof(IO_config) / sizeof(IO_t); i++) {
        if (IO_config[i].descriptor == name) {
            if (IO_config[i].type == GPIO) {
                return get_GPIO_input(IO_config[i].pin);
            } 
            else {
                return MCP23017_get_pin_value(&MCP_expander_1, IO_config[i].pin);
            }
        }
    }
    return -1;//Error
}

/**
 * @brief Sets the output of the specified IO. Still under devel;opment
 *
 * This function sets the output of the specified IO to the specified state.
 *
 * @param name The name of the IO.
 * @param state The state to set the IO to (IO_HIGH or IO_LOW).
 * @return HAL_StatusTypeDef The status of the operation (HAL_OK or HAL_ERROR).
 */
HAL_StatusTypeDef __Set_output(uint8_t name, uint8_t state) {
    for (uint8_t i = 0; i < sizeof(IO_config) / sizeof(IO_t); i++) {
        if (IO_config[i].descriptor == name) {
            if (IO_config[i].type == GPIO) {
                set_GPIO_output(IO_config[i].pin, state);
                return HAL_OK;
            } 
            else {
                return MCP23017_set_pin(&MCP_expander_1, IO_config[i].pin, state);
            }
        }
    }
    return HAL_ERROR;
}

/**
 * @brief Toggles the output of a digital IO based on its name.
 * 
 * This function searches for the digital IO with the specified name in the IO_config array.
 * If the digital IO is found, it toggles the output state based on its type.
 * If the digital IO is of type GPIO, it sets the GPIO output to the opposite of its current input state.
 * If the digital IO is of type MCP23017, it retrieves the current pin value from the MCP23017 expander,
 * and sets the pin to the opposite state.
 * 
 * @param name The name of the digital IO to toggle.
 * @return HAL_StatusTypeDef The status of the operation. HAL_OK if successful, HAL_ERROR otherwise.
 */
HAL_StatusTypeDef __Toogle_output(uint8_t name) {
    for (uint8_t i = 0; i < sizeof(IO_config) / sizeof(IO_t); i++) {
        if (IO_config[i].descriptor == name) {
            if (IO_config[i].type == GPIO) {
                set_GPIO_output(IO_config[i].pin, !get_GPIO_input(IO_config[i].pin));
                return HAL_OK;
            } 
            else {
                uint8_t state = MCP23017_get_pin_value(&MCP_expander_1, IO_config[i].pin);
                return MCP23017_set_pin(&MCP_expander_1, IO_config[i].pin, !state);
            }
        }
    }
    return HAL_ERROR;
}




