#ifndef DIGITAL_IOS_H
#define DIGITAL_IOS_H

#ifdef __cplusplus
extern "C" {
#endif

// Include any necessary libraries or headers here
#include "MCP23017.h"
extern MCP23017 MCP_expander_1;

HAL_StatusTypeDef DINS_init(void);
HAL_StatusTypeDef __Set_output(uint8_t name, uint8_t state);
HAL_StatusTypeDef __Toogle_output(uint8_t name);
GPIO_PinState __Get_io_val(uint8_t name);

#ifdef __cplusplus
}
#endif
#endif // DIGITAL_IOS_H
