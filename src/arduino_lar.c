#include "../include/arduino_lar.h"


void set_pin_mode(uint16_t pin, int mode)
{
    uint8_t reg_data = (1 << _idx_of_pin(pin));
    if (mode == PIN_WRITE) _ddr_of_pin(pin) |= reg_data;
    else _ddr_of_pin(pin) &= ~reg_data;
}

void set_pin_state(uint16_t pin, int state)
{
    uint8_t pin_state = (1<< _idx_of_pin(pin));
    if (state == PIN_HIGH) _prt_of_pin(pin) |= pin_state;
    else _prt_of_pin(pin) &= ~pin_state;
}
