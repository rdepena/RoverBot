#include "Arduino.h"

class Motor {
	public:
		Motor(int directionPin, int brakePin, int throttlePin);
		void Forward(int speed);
		void Reverse(int speed);
		void Brake();
	private:
		int direction;
		int brake;
		int throttle;
};