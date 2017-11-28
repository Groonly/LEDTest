#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include  "Libs\unity\extras\fixture\src\unity_fixture.h"

int main(){
  DDRD |= (1 << PD0);
  while(1){
    PORTD ^= 1 << PD0;
    _delay_ms(3000);
  }
  return 0;
}
