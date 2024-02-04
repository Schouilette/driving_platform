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
    Hb_Led = 1,
    Pb_1 = 2, 
    Pb_2 = 3,
    Sw_1 = 4,
    Sw_2 = 5,
    Sw_3 = 6,
    Sw_4 = 7,
    Sw_5 = 8,
    Led_D3 = 9,
    Led_D4 = 10,
    Led_D5 = 11,
    Led_D6 = 12,
    Led_D7 = 13,
    Led_D8 = 14,
} IO_descriptor_t;


#endif // CONFIG_H
