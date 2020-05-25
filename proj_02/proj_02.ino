int switch_state = 0;
void setup() {
  // Input from switch  
  pinMode(2, INPUT);
  // Green LED
  pinMode(3, OUTPUT);
  // Blue LED
  pinMode(4, OUTPUT);
  // Red LED
  pinMode(5, OUTPUT);

  // Cycle through the LEDs
  int cycle_delay = 125;
  int num_cycles = 10;
  for (int cycle = 0; cycle < num_cycles; cycle++) {
    for (int led_pin = 3; led_pin < 6; led_pin++) {
      digitalWrite(led_pin, HIGH);
      delay(cycle_delay);
      digitalWrite(led_pin, LOW);
    }
  }
}

void loop() {
  switch_state = digitalRead(2);

  int cycle_delay = 150;
  
  if (switch_state == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else {
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    for (int led_pin = 4; led_pin < 6; led_pin++){
      for (int ii = 0; ii < 2; ii++){  
      digitalWrite(led_pin, HIGH);
      delay(cycle_delay);
      digitalWrite(led_pin, LOW);
      delay(cycle_delay);
      } 
    }
  }
}
