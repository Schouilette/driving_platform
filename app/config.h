#ifndef CONFIG_H
#define CONFIG_H

// Add your configuration constants and declarations here
enum{
    DIN1,
    DIN2,
    DIN3,
    DIN4,
    DIN5,
    DIN6,
}

typedef struct{
    uint8_t value;
    uint8_t pin;
}DIN;

DIN din[6] = {
    {0, DIN1},
    {0, DIN2},
    {0, DIN3},
    {0, DIN4},
    {0, DIN5},
    {0, DIN6},
};


#endif // CONFIG_H
