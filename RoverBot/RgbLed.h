#include "Arduino.h"

class RgbLed {
	public:
		RgbLed(int redPin, int greenPin, int bluePin);
		void SetColor(int red, int green, int blue);
	private:
		int _redPin;
		int _greenPin;
		int _bluePin;
};