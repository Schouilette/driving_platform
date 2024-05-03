#ifndef CONFIG_H
#define CONFIG_H

// Descriotion of the IOs
#define IO_MODE_OUTPUT 1
#define IO_MODE_INPUT 0
#define IO_HIGH 1
#define IO_LOW 0

typedef enum {
    MCP23017_1,
    GPIO
} IO_type_t;

typedef enum {
    Hb_Led = 1,  // output
    Pb_1 = 2,    // input
    Pb_2 = 3,    // input
    Sw_1 = 4,    // input
    Sw_2 = 5,    // input
    Sw_3 = 6,    // input
    Sw_4 = 7,    // input
    Sw_5 = 8,    // input
    Led_D3 = 9,  // output
    Led_D4 = 10, // output
    Led_D5 = 11, // output
    Led_D6 = 12, // output
    Led_D7 = 13, // output
    Led_D8 = 14, // output
} IO_descriptor_t;

#endif // CONFIG_H
