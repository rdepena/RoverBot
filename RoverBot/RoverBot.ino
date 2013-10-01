
//https://code.google.com/p/arduino-new-ping/downloads/detail?name=NewPing_v1.5.zip&can=2&q=
#include <NewPing.h>
//not good practice but will have to deal with it for now.

#include "Rover.h"

//Motor A (in the motor shield)
//pin to trigger the spin direction of the motor
#define motorADirection 12
//pin to trigger the break of the motor.
#define motorABrake 9
//pin to trigger the aceleration of the motor.
#define motorAThrotle 3

//Motor B (in the motor shield)
//pin to trigger the spin direction on the motor
#define motorBDirection 13
//pin to trigger the break of the motor
#define motorBBrake 8
//pin to trigger the aceleration of the motor.
#define motorBThrotle 11

//top speed is 255
#define cruiseSpeed 125

//pin to trigger the echo
#define pingTrigger 7
//pin to receive the echo
#define pingEcho 4
// Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define maxDistance 400

//declare a new ping object with a max distance 
NewPing sonar(pingTrigger, pingEcho, maxDistance);

Rover rover(motorADirection, motorABrake, motorAThrotle,
	motorBDirection, motorBBrake, motorBThrotle, 125);

void setup() {

	// //prime to motor pins:
	pinMode(motorADirection, OUTPUT);
	pinMode(motorABrake, OUTPUT);
	pinMode(motorBDirection, OUTPUT);
  	pinMode(motorBBrake, OUTPUT);

 	//NOTE the acelerators on pin 3 and 11 do not have to be primed.
}

void loop() {

	// //Send ping, get ping time in microseconds.
	unsigned int pingMicroseconds = sonar.ping();

		if(pingMicroseconds < 1000) {
		//nothing is in range;
		if(pingMicroseconds == 0){
			rover.Forward(180);
			delay(300);
		}
		//target is in range and aprox 9cm away.
		else {
			rover.LeftTurn(180);
			delay(300);
		}
	}
	//sonar detects something in range but not too close.
	else {
		rover.Forward(180);
		delay(300);
	}	

}