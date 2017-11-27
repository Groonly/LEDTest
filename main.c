#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/power.h>

int main(){
  DDRD |= (1 << PD0);
  while(1){
    toogleLED();
  }
  return 0;
}
