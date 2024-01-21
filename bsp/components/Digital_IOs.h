#ifndef DIGITAL_IOS_H
#define DIGITAL_IOS_H

#ifdef __cplusplus
extern "C" {
#endif

// Include any necessary libraries or headers here
#include "MCP23017.h"
// Define any constants or macros here

// Declare any function prototypes here

// Define any data structures or classes here
typedef struct 
{
  int (*Init)(void);
  int (*Read)(MCP23017* mcp);
} DigitalInputs_t;

typedef struct 
{
  int (*Init)(void);
} DigitalOutputs_t;

// Add your code here
extern DigitalInputs_t DINs;
extern DigitalOutputs_t DOUTs;

#ifdef __cplusplus
}
#endif
#endif // DIGITAL_IOS_H
