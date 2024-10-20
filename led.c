#include "led.h"

// Turn on an LED (positive logic for red/green, negative for blue)
void leds_on(uint8_t ledPin)
{
    if (ledPin == BLUE_LED_PIN)
    {
        gpio_put(ledPin, false); // Negative logic for blue LED (turn ON with LOW)
    }
    else
    {
        gpio_put(ledPin, true); // Positive logic for red/green LEDs (turn ON with HIGH)
    }
}

// Turn off an LED (positive logic for red/green, negative for blue)
void leds_off(uint8_t ledPin)
{
    if (ledPin == BLUE_LED_PIN)
    {
        gpio_put(ledPin, true); // Negative logic for blue LED (turn OFF with HIGH)
    }
    else
    {
        gpio_put(ledPin, false); // Positive logic for red/green LEDs (turn OFF with LOW)
    }
}

void leds_init(void)
{
    gpio_init(RED_LED_PIN); //initialise
    gpio_set_dir(RED_LED_PIN, GPIO_OUT); //ddr

    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);

    gpio_init(BLUE_LED_PIN);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);

    // Turn off all LEDs at start
    leds_off(RED_LED_PIN);
    leds_off(GREEN_LED_PIN);
    leds_off(BLUE_LED_PIN);
}

// Cycle through the LED sequence
void leds_cycle(void)
{
    sleep_ms(5000); //halt for 5 sec

    // Turn on Red LED for 1 second
    leds_on(RED_LED_PIN);
    sleep_ms(1000);
    leds_off(RED_LED_PIN);

    // Turn on Green LED for 1 second
    leds_on(GREEN_LED_PIN);
    sleep_ms(1000);
    leds_off(GREEN_LED_PIN);

    // Turn on Blue LED for 1 second
    leds_on(BLUE_LED_PIN);
    sleep_ms(1000);
    leds_off(BLUE_LED_PIN);

    // Turn on all LEDs for 2 seconds
    leds_on(RED_LED_PIN);
    leds_on(GREEN_LED_PIN);
    leds_on(BLUE_LED_PIN);
    sleep_ms(2000);

    // Turn off all LEDs
    leds_off(RED_LED_PIN);
    leds_off(GREEN_LED_PIN);
    leds_off(BLUE_LED_PIN);
}

int main()
{
    stdio_init_all();

    // Initialize LEDs
    leds_init();

    while (true)
    {
        leds_cycle();
    }
}
