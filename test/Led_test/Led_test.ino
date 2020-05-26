#include <Led.h>

byte led_pins[] = {6, 5};
byte green_led_pin = {4};

Led green_led(&green_led_pin, 1);
Led blue_red_led_array(led_pins, 2);

  
void setup() {
  Serial.begin(9600);
}

void loop() {
  
//  blue_red_led_array.on(1);
  green_led.on();
//  green_led.cycle(10,1000,1000);
  blue_red_led_array.cycle(10, 1000, 1000, 1);
  blue_red_led_array.cycle(10, 1000, 100, 0);
//  if (millis() > 6000){
//    green_led.off();
//  }
}
