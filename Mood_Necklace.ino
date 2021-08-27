#include <Adafruit_NeoPixel.h>

#define PIN	1
#define NUMPIXELS 12
#define BRIGHTNESS 12

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);
#define DELAYVAL 500

void setup() {
	pixels.begin();
	pixels.setBrightness(  BRIGHTNESS );
};

void loop(){
	// leds[0] = CRGB::White; FastLED.show(); delay(1000);
	// leds[0] = CRGB::Black; FastLED.show(); delay(1000);
	// leds[0] = CRGB::Green; FastLED.show(); delay(1000);
	// leds[0] = CRGB::Red; FastLED.show(); delay(1000);
	// leds[0] = CRGB::Blue; FastLED.show(); delay(1000);
	pixels.clear();
	blink();
};

void blink(){
	for(int i=0; i<NUMPIXELS; i++) {
		pixels.setPixelColor(i, pixels.Color(0, 0, 0));
	}
	pixels.show();
	delay(DELAYVAL);
	for(int i=0; i<NUMPIXELS; i++) {
		pixels.setPixelColor(i, pixels.Color(96, 1, 120));
	}
	pixels.show();
	delay(DELAYVAL);
}
