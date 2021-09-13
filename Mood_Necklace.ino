#include <Adafruit_NeoPixel.h>
#include <Adafruit_DotStar.h>

#define LED_PIN	1
#define TEMP_SENSOR_PIN	A1
#define NUMPIXELS 12
#define BRIGHTNESS 12

Adafruit_NeoPixel ring(NUMPIXELS, LED_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_DotStar dot(1, 3, 4, DOTSTAR_BGR);

void setup() {
	pinMode(TEMP_SENSOR_PIN, INPUT);

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
	Serial.println(temperature);

	switch (temperature)
	{
	case 19:
		setRingColor(0, 0, 0); // BLACK
		break;
	case 20:
		setRingColor(0, 95, 60); // RED
		break;
	case 21:
	case 22:
		setRingColor(23, 95, 60); // ORANGE
		break;
	case 23:
		setRingColor(51, 95, 60); // YELLOW
		break;
	case 24:
	case 25:
		setRingColor(76, 95, 60); // LIME-GREEN
		break;
	case 26:
		setRingColor(109, 95, 60); // GREEN
		break;
	case 27:
		setRingColor(139, 95, 60); // GREEN-BLUE
		break;
	case 28:
		setRingColor(162, 95, 60); // TURQUOISE
		break;
	case 29:
		setRingColor(182, 95, 60); // CYAN
		break;
	case 30:
		setRingColor(222, 95, 60); // BLUE
		break;
	case 31:
		setRingColor(265, 95, 60); // PURPLE
		break;
	case 32:
		setRingColor(306, 95, 60); // VIOLET
		break;
	case 33:
		setRingColor(336, 95, 60); // PINK
		break;
	default:
		setRingColor(0, 0, 60); // WHITE
	}
};

void setRingColor(uint16_t hue, uint8_t sat, uint8_t val){
	int j;
	for (j = 0; j <= 36; j += 4)
	{
		ring.fill(fromHSVtoRGB(hue, sat, max(val - j, 0)));
		dot.fill(fromHSVtoRGB(hue, sat, max(val - j, 0)));
		ring.show();
		dot.show();
		delay(25);
	}
	for (; j >= 0; j -= 4) {
		ring.fill(fromHSVtoRGB(hue, sat, max(val - j, 0)));
		dot.fill(fromHSVtoRGB(hue, sat, max(val - j, 0)));
		ring.show();
		dot.show();
		delay(25);
	}
}

uint32_t fromHSVtoRGB(uint16_t hue, uint8_t sat, uint8_t val) {
	Serial.print("hue ");
	Serial.println(hue);
	Serial.print("sat ");
	Serial.println(sat);
	Serial.print("val ");
	Serial.println(val);
	double c = (val/100.0) * (sat/100.0);
	// double c = 0.57;
	double x = c * (1 - abs((hue / 60) % 2 + (hue / 60.0 - (int)(hue/60)) - 1));
	// double x = c * (1 - abs(0 % 2 + 0.38333 - 1));
	// double x = c * (1 - 0.616666);
	// double x = 0.2185;
	double m = (val/100.0) - c;
	// double m = 0.6 - c;
	// double m = 0.03;
	double r;
	double g;
	double b;
	Serial.print("c ");
	Serial.println(c);
	Serial.print("x ");
	Serial.println(x);
	Serial.print("m ");
	Serial.println(m);
	
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
	Serial.print("rfinal ");
	Serial.println(rfinal);
	Serial.print("gfinal ");
	Serial.println(gfinal);
	Serial.print("bfinal ");
	Serial.println(bfinal);

	return ring.Color(rfinal, gfinal, bfinal);
}
