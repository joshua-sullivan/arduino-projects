/*
    This is a class for a generic pushbotton "sensor".
    Josh Sullivan
    2020/05/24
*/
#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button
{

private:
    // Pin that the button is connected to
    byte pin;
    // Current state of the button
    byte state;
    // Last reading of the button
    byte last_reading;

    // Time at which button state was last changed [ms]
    unsigned long last_debounce_time = 0;
    // Threshold for proper button state change [ms]
    unsigned long debounce_delay = 50;

public:
    // Button constructor
    Button(byte pin);

    // Initialize the button
    void init();
    // Take care of debounce and update state
    void update();

    // Queries the state of the button
    byte get_state();

    // Checks if button is pressed
    bool is_pressed();
};

#endif