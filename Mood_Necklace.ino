#include <Adafruit_NeoPixel.h>
#include <Adafruit_DotStar.h>

#define NUMPIXELS 12
#define BRIGHTNESS 12

enum pins {
	LED_PIN = 1, TEMP_SENSOR_PIN = A1, PHOTOCELL_PIN = A2
};
enum brightness_range
{
	BRIGHTNESS_MIN = 40,
	BRIGHTNESS_MAX = 100
};

enum photocell_range
{
	PHOTOCELL_MIN = 60,
	PHOTOCELL_MAX = 400
};

Adafruit_NeoPixel ring(NUMPIXELS, LED_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_DotStar dot(1, 3, 4, DOTSTAR_BGR);

void setup() {
	pinMode(TEMP_SENSOR_PIN, INPUT);
  	pinMode(PHOTOCELL_PIN, INPUT);

	ring.begin();
	ring.setBrightness(BRIGHTNESS);
	dot.begin();
	dot.setBrightness(BRIGHTNESS);
};

void loop(){
	ring.clear();
	dot.clear();
	int temp_sensor = analogRead(TEMP_SENSOR_PIN);
	int milliVolts = (temp_sensor) * (3300 / 1024);
	int temperature = ( milliVolts - 500 ) / 10;
	int photocell = analogRead(PHOTOCELL_PIN);
  	Serial.println(photocell);
  	int brightness = constrain(map(photocell, PHOTOCELL_MIN, PHOTOCELL_MAX, BRIGHTNESS_MIN, BRIGHTNESS_MAX), BRIGHTNESS_MIN, BRIGHTNESS_MAX);
  	Serial.println(brightness);

	switch (temperature)
	{
	case 19:
		setRingColor(0, 0, 0); // BLACK
		break;
	case 20:
		setRingColor(0, 95, brightness); // RED
		break;
	case 21:
	case 22:
		setRingColor(23, 95, brightness); // ORANGE
		break;
	case 23:
		setRingColor(51, 95, brightness); // YELLOW
		break;
	case 24:
	case 25:
		setRingColor(76, 95, brightness); // LIME-GREEN
		break;
	case 26:
		setRingColor(109, 95, brightness); // GREEN
		break;
	case 27:
		setRingColor(139, 95, brightness); // GREEN-BLUE
		break;
	case 28:
		setRingColor(162, 95, brightness); // TURQUOISE
		break;
	case 29:
		setRingColor(182, 95, brightness); // CYAN
		break;
	case 30:
		setRingColor(222, 95, brightness); // BLUE
		break;
	case 31:
		setRingColor(265, 95, brightness); // PURPLE
		break;
	case 32:
		setRingColor(306, 95, brightness); // VIOLET
		break;
	case 33:
		setRingColor(336, 95, brightness); // PINK
		break;
	default:
		setRingColor(0, 0, brightness); // WHITE
	}
};

void setRingColor(uint16_t hue, uint8_t sat, uint8_t val){
	int j;
	for (j = val; j >= val/2; j -= 4)
	{
		ring.fill(fromHSVtoRGB(hue, sat, j));
		dot.fill(fromHSVtoRGB(hue, sat, j));
		ring.show();
		dot.show();
		delay(25);
	}
	for (; j <= val; j += 4) {
		ring.fill(fromHSVtoRGB(hue, sat, j));
		dot.fill(fromHSVtoRGB(hue, sat, j));
		ring.show();
		dot.show();
		delay(25);
	}
}

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
	double rfinal = (uint16_t)((r + m) * 255);
	double gfinal = (uint16_t)((g+m)*255);
	double bfinal = (uint16_t)((b+m)*255);

	return ring.Color(rfinal, gfinal, bfinal);
}
