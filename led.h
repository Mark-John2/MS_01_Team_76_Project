#ifndef LEDS_H
#define LEDS_H

#include "pico/stdlib.h" //Pico SDK standard library, which provides access to functions for controlling hardware peripherals such as GPIO and sleep
#include <stdio.h> //serial communication to print messages for debugging or interacting with the device.

// Define LED pins
#define RED_LED_PIN 13
#define GREEN_LED_PIN 12
#define BLUE_LED_PIN 27
#define OUTPUT 1

// Function signatures
void leds_init(void);
void leds_on(uint8_t ledPin);
void leds_off(uint8_t ledPin);
void leds_cycle(void);

#endif 
