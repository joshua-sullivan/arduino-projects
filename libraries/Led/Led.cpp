#include "Led.h"

// Construct the Led object
Led::Led(byte pin)
{
    this->pin = pin;
    init();
}

// Initialize the Led
void Led::init()
{
    pinMode(pin, OUTPUT);
    off();
}

// Turn the LED on
void Led::on()
{
    digitalWrite(pin, HIGH);
    turned_on_time = millis();
    state = HIGH;
}

// Turn the LED off
void Led::off()
{
    digitalWrite(pin, LOW);
    turned_off_time = millis();
    state = LOW;
}

bool Led::is_on()
{
    return (state == HIGH);
}

// Cycle the LED on and off a specified number of times,
// with the on/off duration specified
void Led::cycle(int num_cycles, int on_time, int off_time)
{
    unsigned long dt_on = millis() - turned_on_time;
    unsigned long dt_off = millis() - turned_off_time;

    if (!is_on() && current_num_cycles == 0)
    {
        on();
    }

    if (is_on())
    {
        if (dt_on >= on_time)
        {
            off();
            current_num_cycles += 1;
        }
    }

    else
    {
        if (dt_off >= off_time && current_num_cycles < num_cycles)
        {
            on();
        }
    }
}