#include "Motor.h"

class Rover {
	public:
		Rover(int directionPinA, int brakePinA, int throttlePinA, 
			int directionPinB, int brakePinB, int throttlePinB, int cruisingSpeed);
		void Forward(int speed);
		void Reverse(int speed);
		void LeftTurn(int speed);
		void RightTurn(int speed);
		void Brake();
	private:
		Motor MotorA;
		Motor MotorB;
		int cruiseSpeed;
};