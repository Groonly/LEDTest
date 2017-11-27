#include "func.h"


void toogleLED(){
  _delay_ms(LEDDELAY);
  PORTD ^= 1 << PD0;
}
