#include "../../include/arduino_lar.h"

int main ()
{

    set_pin_mode(PIN_0, PIN_WRITE);
    set_pin_state(PIN_0, PIN_HIGH);
    set_pin_mode(PIN_1, PIN_WRITE);
    set_pin_state(PIN_1, PIN_HIGH);
    set_pin_mode(PIN_2, PIN_WRITE);
    set_pin_state(PIN_2, PIN_HIGH);
    set_pin_mode(PIN_3, PIN_WRITE);
    set_pin_state(PIN_3, PIN_HIGH);
    set_pin_mode(PIN_4, PIN_WRITE);
    set_pin_state(PIN_4, PIN_HIGH);
    set_pin_mode(PIN_5, PIN_WRITE);
    set_pin_state(PIN_5, PIN_HIGH);
    set_pin_mode(PIN_6, PIN_WRITE);
    set_pin_state(PIN_6, PIN_HIGH);
    set_pin_mode(PIN_7, PIN_WRITE);
    set_pin_state(PIN_7, PIN_HIGH);
    set_pin_mode(PIN_8, PIN_WRITE);
    set_pin_state(PIN_8, PIN_HIGH);
    set_pin_mode(PIN_9, PIN_WRITE);
    set_pin_state(PIN_9, PIN_HIGH);
    set_pin_mode(PIN_10, PIN_WRITE);
    set_pin_state(PIN_10, PIN_HIGH);
    set_pin_mode(PIN_11, PIN_WRITE);
    set_pin_state(PIN_11, PIN_HIGH);
    set_pin_mode(PIN_12, PIN_WRITE);
    set_pin_state(PIN_12, PIN_HIGH);
    set_pin_mode(PIN_13, PIN_WRITE);
    set_pin_state(PIN_13, PIN_HIGH);

    serial_init(STANDARD_BAUDRATE);

    serial_println("Gib ein Satz ein und drücke dann Enter:");

    char* b = serial_visual_readln(200);

    serial_print("Dein Satz war: ");
    serial_println(b);

}
