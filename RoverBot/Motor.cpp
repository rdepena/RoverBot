#include "Motor.h"

Motor::Motor(int directionPin, int brakePin, int throttlePin) {
	direction = directionPin;
	brake = brakePin;
	throttle = throttlePin;
}
//Moves a single motor forward
void Motor::Forward(int speed) {
	//make sure we are not breaking
	digitalWrite(brake, LOW);
	//set the motor in forward motion
	digitalWrite(direction, HIGH);
	//acelerate
	analogWrite(throttle, speed);
}
//Moves a single motor in reverse
void Motor::Reverse(int speed) {
	//make sure we are not breaking
	digitalWrite(brake, LOW);
	//set the motor in reverse motion
	digitalWrite(direction, LOW);
	//acelerate
	analogWrite(throttle, speed);
}
//Breaks a single motor.
void Motor::Brake() {
	digitalWrite(brake, HIGH);
}