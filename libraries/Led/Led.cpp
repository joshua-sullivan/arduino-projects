#include "Led.h"

// Construct the Led object
Led::Led(byte *pins, unsigned int num_leds)
{
    // Allocating memory for pins and populating the data
    this->pins = new byte[num_leds];
    for (byte led = 0; led < num_leds; led++)
    {
        this->pins[led] = pins[led];
    }

    this->num_leds = num_leds;

    // Dynamically allocating memory for the array since size isn't known
    // at compile time
    this->states = new byte[num_leds];
    this->turned_on_times = new unsigned long[num_leds];
    this->turned_off_times = new unsigned long[num_leds];
    this->current_num_cycles = new int[num_leds];

    init();
}

// Destruct the Led object
Led::~Led()
{
    delete[] pins;
    delete[] states;
    delete[] turned_on_times;
    delete[] turned_off_times;
    delete[] current_num_cycles;
}

// Initialize the LEDs
void Led::init()
{
    for (byte led = 0; led < this->num_leds; led++)
    {
        pinMode(this->pins[led], OUTPUT);
        this->turned_on_times[led] = 0;
        this->turned_off_times[led] = 0;
        this->current_num_cycles[led] = 0;
        off(led);
    }
}

// Turn LEDs
void Led::on(unsigned int led_idx = 0)
{
    digitalWrite(this->pins[led_idx], HIGH);
    this->turned_on_times[led_idx] = millis();
    this->states[led_idx] = HIGH;
}

// Turn the LED off
void Led::off(unsigned int led_idx = 0)
{
    digitalWrite(this->pins[led_idx], LOW);
    this->turned_off_times[led_idx] = millis();
    this->states[led_idx] = LOW;
}

bool Led::is_on(unsigned int led_idx = 0)
{
    return (this->states[led_idx] == HIGH);
}

// Cycle the LED on and off a specified number of times,
// with the on/off duration specified
void Led::cycle(int num_cycles, int on_time, int off_time, unsigned int led_idx = 0)
{
    unsigned long dt_on = millis() - this->turned_on_times[led_idx];
    unsigned long dt_off = millis() - this->turned_off_times[led_idx];

    if (!is_on(led_idx) && this->current_num_cycles[led_idx] == 0)
    {
        on(led_idx);
    }

    if (is_on(led_idx))
    {
        if (dt_on >= on_time)
        {
            off(led_idx);
            this->current_num_cycles[led_idx] += 1;
        }
    }

    else
    {
        if (dt_off >= off_time && this->current_num_cycles[led_idx] < num_cycles)
        {
            on(led_idx);
        }
    }
}