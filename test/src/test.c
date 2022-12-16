#include "../../include/arduino_lar.h"

int main ()
{
    serial_init(STANDARD_BAUDRATE);
    serial_print("Test");
}
