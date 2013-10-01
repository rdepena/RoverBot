#include "Rover.h"

Rover::Rover(int directionPinA, int brakePinA, int throttlePinA, 
	int directionPinB, int brakePinB, 
	int throttlePinB, int cruisingSpeed):MotorA(directionPinA,brakePinA,throttlePinA)
	,MotorB(directionPinB,brakePinB,throttlePinB){
	cruiseSpeed = cruisingSpeed;
}
//The rover moves forward
void Rover::Forward(int speed) {
	MotorA.Forward(speed);
	MotorB.Forward(speed);
}
//the rover moves in reverse
void Rover::Reverse(int speed) {
	MotorA.Reverse(speed);
	MotorB.Reverse(speed);
}
//the rover breaks.
void Rover::Brake() {
	MotorA.Brake();
	MotorB.Brake();
}
void Rover::LeftTurn(int speed) {
	MotorA.Reverse(speed);
	MotorB.Forward(speed);
}

void Rover::RightTurn(int speed) {
	MotorA.Forward(speed);
	MotorB.Forward(speed);
}
