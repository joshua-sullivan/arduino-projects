/*
    This is a class for a generic LED "actuator".
    Josh Sullivan
    2020/05/24
*/
#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led
{

private:
    // Pin that the LED is connected to
    byte pin;
    // LED state (HIGH or LOW)
    byte state;

    // Time at which the LED was switched on
    unsigned long turned_on_time = 0;
    // Time at which the LED was switched off
    unsigned long turned_off_time = 0;

    // Track number of cycles conducted
    int current_num_cycles = 0;

public:
    // Led constructor
    Led(byte pin);
    // Initialize the LED
    void init();
    // Turn the LED on
    void on();
    // Turn the LED off
    void off();
    // Cycle the LED on and off
    void cycle(int num_cycles, int on_time, int off_time);
    // Check if the LED is on
    bool is_on();
};

#endif