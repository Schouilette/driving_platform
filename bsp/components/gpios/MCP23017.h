#ifndef MCP23017_H
#define MCP23017_H

#include "stm32f4xx_hal.h"

// Constants
#define MCP23017_ADDRESS 0x20
// Ports
#define MCP23017_PORTA			0x00
#define MCP23017_PORTB			0x01

#define PORTA_OFFSET            0x00
#define PORTB_OFFSET            0x08
// I/O Direction
// Default state: MCP23017_IODIR_ALL_INPUT
#define MCP23017_IODIR_ALL_OUTPUT	0x00
#define MCP23017_IODIR_ALL_INPUT	0xFF
#define MCP23017_IODIR_IO0_INPUT	0x01
#define MCP23017_IODIR_IO1_INPUT	0x02
#define MCP23017_IODIR_IO2_INPUT	0x04
#define MCP23017_IODIR_IO3_INPUT	0x08
#define MCP23017_IODIR_IO4_INPUT	0x10
#define MCP23017_IODIR_IO5_INPUT	0x20
#define MCP23017_IODIR_IO6_INPUT	0x40
#define MCP23017_IODIR_IO7_INPUT	0x80

#define MCP23017_IODIR_IO0_OUTPUT	0xFE
#define MCP23017_IODIR_IO1_OUTPUT	0xFD
#define MCP23017_IODIR_IO2_OUTPUT	0xFB
#define MCP23017_IODIR_IO3_OUTPUT	0xF7
#define MCP23017_IODIR_IO4_OUTPUT	0xEF
#define MCP23017_IODIR_IO5_OUTPUT	0xDF
#define MCP23017_IODIR_IO6_OUTPUT	0xBF
#define MCP23017_IODIR_IO7_OUTPUT	0x7F

// Data structures
typedef struct {
    uint8_t address;
    uint16_t iodir;
    uint16_t gpio_value;
    I2C_HandleTypeDef* i2c;
} MCP23017;

// Function prototypes
HAL_StatusTypeDef MCP23017_init(MCP23017* mcp, I2C_HandleTypeDef* i2c, uint8_t address);
void MCP23017_deinit(MCP23017* mcp);

HAL_StatusTypeDef MCP23017_set_all_pins_dir(MCP23017* mcp, uint16_t dir);
HAL_StatusTypeDef MCP23017_set_pin_dir(MCP23017* mcp, uint16_t pin, uint16_t dir);
HAL_StatusTypeDef MCP23017_set_all_pins(MCP23017* mcp, uint16_t value);
HAL_StatusTypeDef MCP23017_set_pin(MCP23017* mcp, uint16_t pin, uint8_t value);
uint16_t MCP23017_get_all_pins_value(MCP23017* mcp);
uint8_t MCP23017_get_pin_value(MCP23017* mcp, uint16_t pin);

#endif
