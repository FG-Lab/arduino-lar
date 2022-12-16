#ifndef ARDUINO_H
#define ARDUINO_H

#include <inttypes.h>
#include "register_offsets.h"

// define pins and retrieve information about them
#define _8bit_addr_from(addr) (*(volatile uint8_t*) addr)
#define _define_pin(reg_addr, port) (0b0000000000000000 | (((reg_addr)<< 8) | (port)))
#define _ddr_of_pin(pin) _8bit_addr_from((pin >> 8))
#define _prt_of_pin(pin) _8bit_addr_from(((pin >> 8)+0x01))
#define _idx_of_pin(pin) ((uint8_t)(pin & 0b0000000011111111))

// Serial Communication Defines
#define STANDARD_BAUDRATE 9600
#define CLOCK_SPEED 16000000

// Pins
#define PIN_13 _define_pin(0x24, 5)
#define PIN_12 _define_pin(0x24, 4)
#define PIN_11 _define_pin(0x24, 3)
#define PIN_10 _define_pin(0x24, 2)
#define PIN_9 _define_pin(0x24, 1)
#define PIN_8 _define_pin(0x24, 0)
#define PIN_7 _define_pin(0x2A, 7)
#define PIN_6 _define_pin(0x2A, 6)
#define PIN_5 _define_pin(0x2A, 5)
#define PIN_4 _define_pin(0x2A, 4)
#define PIN_3 _define_pin(0x2A, 3)
#define PIN_2 _define_pin(0x2A, 2)
#define PIN_1 _define_pin(0x2A, 1)
#define PIN_0 _define_pin(0x2A, 0)


// Pin modes
#define PIN_READ  0
#define PIN_WRITE 1

// Pin output states
#define PIN_LOW  0
#define PIN_HIGH 1

void set_pin_mode(uint16_t pin, int mode);
void set_pin_state(uint16_t pin, int mode);

void serial_init(uint16_t baudrate);
void serial_put_char(char data);
void serial_print(const char* str);
void serial_println(const char* str);
char serial_read();
char* serial_readln(int max_len);
char* serial_visual_readln(int max_len);

#endif
