#include <Adafruit_NeoPixel.h>

#define LED_PIN	1
#define TEMP_SENSOR_PIN	A1
#define NUMPIXELS 12
#define BRIGHTNESS 12

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRBW + NEO_KHZ800);
#define DELAYVAL 500

void setup() {
	pinMode(TEMP_SENSOR_PIN, INPUT);

	pixels.begin();
	pixels.setBrightness(  BRIGHTNESS );
};

void loop(){
	pixels.clear();
	int temp_sensor = analogRead(TEMP_SENSOR_PIN);
	int milliVolts = (temp_sensor) * (3300 / 1024);
	int temperature = ( milliVolts - 500 ) / 10;
	Serial.println(temperature);
	switch (temperature)
	{
	case 19:
		setRingColor(0, 0, 0); // BLACK
		break;
	case 20:
		setRingColor(0, 95, 32); // RED
		break;
	case 21:
	case 22:
		setRingColor(23, 95, 32); // ORANGE
		break;
	case 23:
		setRingColor(51, 95, 32); // YELLOW
		break;
	case 24:
	case 25:
		setRingColor(76, 95, 32); // LIME-GREEN
		break;
	case 26:
		setRingColor(109, 95, 32); // GREEN
		break;
	case 27:
		setRingColor(139, 95, 32); // GREEN-BLUE
		break;
	case 28:
		setRingColor(162, 95, 32); // TURQUOISE
		break;
	case 29:
	case 30:
		setRingColor(182, 95, 32); // CYAN
		break;
	case 31:
		setRingColor(245, 95, 32); // BLUE
		break;
	case 32:
		setRingColor(271, 95, 32); // VIOLET
		break;
	case 33:
		setRingColor(306, 95, 32); // PINK
		break;
	default:
		setRingColor(0, 0, 32); // WHITE
	}
};

void setRingColor(uint16_t hue, uint8_t sat, uint8_t val){
	double valdim = val - 10;

	// pixels.fill() for all of them in the same color
	for(int i=0; i<NUMPIXELS; i++) {
		pixels.setPixelColor(i, fromHSVtoRGB(hue, sat, valdim));
	}

	pixels.show();
	delay(DELAYVAL);
	for(int i=0; i<NUMPIXELS; i++) {
		pixels.setPixelColor(i, fromHSVtoRGB(hue, sat, val));
	}
	pixels.show();
	delay(DELAYVAL);
}

// get the hsv, change the value of the val and convert it to rgb to call pixels.Color
// https://www.rapidtables.com/convert/color/rgb-to-hsv.html

// adafruit docs https://github.com/adafruit/Adafruit_NeoPixel/blob/master/Adafruit_NeoPixel.h

uint32_t fromHSVtoRGB(uint16_t hue, uint8_t sat, uint8_t val) {
	double c = (val/100.0) * (sat/100.0);
	double x = c * (1 - abs((hue / 60) % 2 + (hue / 60.0 - (int)(hue/60)) - 1));
	double m = (val/100.0) - c;
	double r;
	double g;
	double b;
	
	if (0 <= hue && hue < 60) {
		r = c;
		g = x;
		b = 0;
	} else if (60 <= hue && hue < 120) {
		r = x;
		g = c;
		b = 0;
	} else if (120 <= hue && hue < 180) {
		r = 0;
		g = c;
		b = x;
	} else if (180 <= hue && hue < 240) {
		r = 0;
		g = x;
		b = c;
	} else if (240 <= hue && hue < 300) {
		r = x;
		g = 0;
		b = c;
	} else if (300 <= hue && hue < 360) {
		r = c;
		g = 0;
		b = x;
	} else {
		r = 0;
		g = 0;
		b = 0;
	}


	Serial.print("r: ");
	Serial.println((r+m)*255);
	Serial.print("g: ");
	Serial.println((g+m)*255);
	Serial.print("b: ");
	Serial.println((b+m)*255);

	return pixels.Color((uint16_t)((r+m)*255), (uint16_t)((g+m)*255), (uint16_t)((b+m)*255));
}
