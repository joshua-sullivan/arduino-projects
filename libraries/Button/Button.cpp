#include "Button.h"

// Construct the Button object
Button::Button(byte pin)
{
    this->pin = pin;
    last_reading = LOW;
    init();
}

// Initialize the button
void Button::init()
{
    pinMode(pin, INPUT);
    update();
}

// Debounce button signal and update state
void Button::update()
{
    // Take a new reading
    byte new_reading = digitalRead(pin);

    // If the switch changed, due to noise or pressing,
    // reset the debounce timer
    if (new_reading != last_reading)
    {
        last_debounce_time = millis();
    }
    // If the reading has been there longer than the debounce
    // delay, take it as the actual current state
    if (millis() - last_debounce_time > debounce_delay)
    {
        if (state != new_reading)
        {
            state = new_reading;
        }
    }

    // Update the reading tracker for the next time it's called
    last_reading = new_reading;
}

// Query for an updated state and return it
byte Button::get_state()
{
    update();

    return state;
}

// Check if the button is pressed
bool Button::is_pressed()
{
    return (get_state() == HIGH);
}