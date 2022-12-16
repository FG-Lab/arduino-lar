#include "../../include/arduino_lar.h"
#include <util/delay.h>

int main ()
{
  // Make pin 13 a output pin.
   set_output_pin(PIN_13);

   while (1)
   {
       // Turn the LED on
       set_pin_high(PIN_13);

       // Wait 1 second
       _delay_ms(1000);

       // Turn the LED of
       set_pin_low(PIN_13);

       // wait 1/4 Second
       _delay_ms(250);
   }
}
