#include "FastLED.h"

enum pins
{
	LED_PIN = 1
};

enum led_settings
{
	NUM_LEDS = 12
};

CRGB leds[NUM_LEDS];

void setup() {
   FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);  // Set up neopixels with FastLED
};

void loop(){
	leds[0] = CRGB::White; FastLED.show(); delay(1000);
	leds[0] = CRGB::Black; FastLED.show(); delay(1000);
	leds[0] = CRGB::Green; FastLED.show(); delay(1000);
	leds[0] = CRGB::Red; FastLED.show(); delay(1000);
	leds[0] = CRGB::Blue; FastLED.show(); delay(1000);
};