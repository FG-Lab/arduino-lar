#include "../../include/arduino_lar.h"

int main ()
{
    serial_init(STANDARD_BAUDRATE);
    serial_print("Gib ein Buchstaben ein\n\r");

    char b = serial_read();

    serial_print("Dein Buchstabe war: ");
    serial_put_char(b);
}
