#include <inttypes.h>
#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>

void sleep(uint8_t millis) {
  while(millis) {
    _delay_ms(1);
    millis--;
  }
}

int main(void) {

  DDRB |= 1 << PB6;
  DDRB |= 1 << PB7;
  for(;;) {
    PORTB &= ~(1 << PB6); // low
    PORTB &= ~(1 << PB7); // low
    sleep(100);
    PORTB |= (1 << PB6); // high
    PORTB |= (1 << PB7); // high
    sleep(100);
  }

  return 0;
}
