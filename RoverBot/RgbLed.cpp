#include "RgbLed.h"

RgbLed::RgbLed(int redPin, int greenPin, int bluePin) {
	_redPin = redPin;
	_greenPin = greenPin;
	_bluePin = bluePin;
}

void RgbLed::SetColor(int red, int green, int blue) {
	analogWrite(_redPin, red);
	analogWrite(_greenPin, green);
	analogWrite(_bluePin, blue);		
}