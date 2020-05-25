#include <Led.h>

Led red_led(5);
Led green_led(4);
  
void setup() {
  green_led.on();
}

void loop() {
  red_led.cycle(10, 1000, 1000);
  if (millis() > 6000){
    green_led.off();
  }

}
