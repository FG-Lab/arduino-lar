# arduino-lar

Provides basic util functions for an Arduino UNO.

```c
#include "../../include/arduino_lar.h"
#include <util/delay.h>

/*
 *  The onboard LED should start blinking.
 */

int main ()
{
    // Make pin 13 a output pin.
    set_pin_mode(PIN_13, PIN_WRITE);

    while (1)
    {
        // Turn the LED on
        set_pin_state(PIN_13, PIN_HIGH);
        
        // Wait 1 second
        _delay_ms(1000);
        
        // Turn the LED of
        set_pin_state(PIN_13, PIN_LOW);
        
        // wait 1/4 Second
        _delay_ms(250);
    }
}
```

## Dependencies
* avrdude
* avr-gcc
* avr-libc

Installation on Arch/Manjaro/EndavourOS
```shell
sudo pacman -S --needed avrdude avr-gcc avr-libc
```

Installation on Dabian/Mint/Ubuntu
```shell
sudo apt install avrdude gcc-avr avr-libc
```

## Building Arduino_LAR

Build the library using
```shell
make lib
```

After that copy the "include" and "lib" directories into your project
and link with the library.
