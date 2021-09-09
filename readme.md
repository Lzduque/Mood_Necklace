- Install the FastLED library to deal with the LEDs:
https://github.com/FastLED/FastLED

- As a base, I used the following tutorial:
https://learn.adafruit.com/gemma-color-touch-pendant-necklace/software

- Gemma M0 is not installed as default on arduino IDE, so you gotta install it:
https://learn.adafruit.com/adafruit-gemma-m0/arduino-ide-setup

- The default for LED lights is RGB (libraries like FastLED use it) since Neopixel ring uses GRB, you have to fix it:
https://github.com/FastLED/FastLED/wiki/Rgb-calibration

- Base to set the color and temperature:
https://www.philophrosyne.com/blogs/jewelry-guide/what-do-the-colors-of-a-mood-ring-mean

- HSV cnverter to RGB formula:
https://www.rapidtables.com/convert/color/hsv-to-rgb.html

- Adafruit docs:
https://github.com/adafruit/Adafruit_NeoPixel/blob/master/Adafruit_NeoPixel.h
