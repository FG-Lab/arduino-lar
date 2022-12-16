#include "../../include/arduino_lar.h"
#include <util/delay.h>


int main ()
{
    set_pin_mode(PIN_13, PIN_WRITE);

    while (1)
    {
        set_pin_state(PIN_13, PIN_HIGH);
        _delay_ms(1000);
        set_pin_state(PIN_13, PIN_LOW);
        _delay_ms(250);
    }
}