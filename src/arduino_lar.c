#include <string.h>
#include <stdlib.h>
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

void set_pin_high(uint16_t pin)
{
  set_pin_state(pin, 1);
}

void set_pin_low(uint16_t pin)
{
  set_pin_state(pin, 0);
}

void set_output_pin(uint16_t pin)
{
  set_pin_mode(pin, 1);
}
void set_input_pin(uint16_t pin)
{
  set_pin_mode(pin, 0);
}

void serial_init(uint16_t baudrate)
{
    uint16_t baud = CLOCK_SPEED / 16 / baudrate -1;
    _8bit_addr_from(UBRR0H_ADDR) = (uint8_t) (baud >> 8);
    _8bit_addr_from(UBRR0L_ADDR) = (uint8_t) baud;

    _8bit_addr_from(UCSR0B_ADDR) = (1<<RXEN0_INDX) | (1<<TXEN0_INDX);
    _8bit_addr_from(UCSR0C_ADDR) = (1<<USBS0_INDX) | (3<<UCSZ00_INDX);
}

void serial_put_char(char data)
{
    while (!(_8bit_addr_from(UCSR0A_ADDR) & (1<<UDRE0_INDX)));
    _8bit_addr_from(UDR0_ADDR) = data;
}

void serial_print(const char * str)
{
    for (int i=0; str[i]!='\0'; i++)
    {
        serial_put_char(str[i]);
    }
}

void serial_println(const char* str)
{
    serial_print(str);
    serial_print("\n\r");
}

char serial_read()
{
    while (!(_8bit_addr_from(UCSR0A_ADDR) & (1<<RXC0_INDX)));
    return _8bit_addr_from(UDR0_ADDR);
}

char* serial_readln(int max_len)
{
    char* result = malloc(10 * sizeof(char));

    int i;
    for (i=0; i<max_len; i++)
    {
        char current = serial_read();
        if (current == '\r') break;
        result[i] = current;
    }

    result[i] = '\0';

    return result;
}

char* serial_visual_readln(int max_len)
{
    char* result = malloc(10 * sizeof(char));

    int i;
    for (i=0; i<max_len; i++)
    {
        char current = serial_read();
        if (current == '\r') break;
        serial_put_char(current);
        result[i] = current;
    }

    result[i] = '\0';
    serial_print("\n\r");

    return result;
}
