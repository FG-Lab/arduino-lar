#ifndef ARDUINO_H
#define ARDUINO_H

#include <inttypes.h>

#define AVR_MEM_OFFSET 0x20

// define pins and retrieve information about them
#define _define_pin(reg_addr, port) (0b0000000000000000 | (((reg_addr+AVR_MEM_OFFSET)<< 8) | (port)))
#define _ddr_of_pin(pin) (*(volatile uint8_t*)(pin >> 8))
#define _prt_of_pin(pin) (*(volatile uint8_t*)((pin >> 8)+0x01))
#define _idx_of_pin(pin) ((uint8_t)(pin & 0b0000000011111111))

// Pins
#define PIN_13 _define_pin(0x04, 5)
#define PIN_2 _define_pin(0x0A, 2)

// Pin modes
#define PIN_READ  0
#define PIN_WRITE 1

// Pin output states
#define PIN_LOW  0
#define PIN_HIGH 1

void set_pin_mode(uint16_t pin, int mode);
void set_pin_state(uint16_t pin, int mode);

#endif