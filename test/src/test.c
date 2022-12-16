#include "../../include/arduino_lar.h"

int main ()
{
    serial_init(STANDARD_BAUDRATE);

    serial_println("Gib ein Satz ein und drücke dann Enter:");

    char* b = serial_visual_readln(200);

    serial_print("Dein Satz war: ");
    serial_println(b);
}
