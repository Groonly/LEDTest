#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/power.h>

#include "AVR-Test-Library/func.h"

int main(){
  DDRD |= (1 << PD0);
  while(1){
    _delay_ms(A);
    PORTD ^= (1 << PD0);
  }
  return 0;
}
