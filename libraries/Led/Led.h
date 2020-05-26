/*
    This is a class for a generic set of LED "actuators".
    Josh Sullivan
    2020/05/24
*/
#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led
{

private:
    // Pins that the LEDs are connected to
    byte *pins;
    // LED state (HIGH or LOW)
    byte *states;

    // Time at which each LED was switched on
    unsigned long *turned_on_times;
    // Time at which each LED was switched off
    unsigned long *turned_off_times;

    // Track number of cycles conducted for each LED
    int *current_num_cycles;
    // Number of LEDs
    unsigned int num_leds;

public:
    // Led constructor
    Led(byte *pins, unsigned int num_leds);
    // LED destructor
    ~Led();
    // Initialize the LEDs
    void init();
    // Turn an LED on
    void on(unsigned int led_idx = 0);
    // Turn an LED off
    void off(unsigned int led_idx = 0);
    // Cycle an LED on and off
    void cycle(int num_cycles, int on_time, int off_time, unsigned int led_idx = 0);
    // Check if the LED is on
    bool is_on(unsigned int led_idx = 0);
};

#endif