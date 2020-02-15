/*
 Stepper Motor Control - speed control

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.
 A potentiometer is connected to analog input 0.

 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps,
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.

 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
bool direction = true; //true for ccw, false cw
//pins 8-11: Green red yellow blue

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); //SWITCH PINS TO CHANGE DIRECTION

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  // nothing to do inside the setup
  Serial.begin(9600);
}

void flipDir(){
    if (flipDir){
        Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); //SWITCH PINS TO CHANGE DIRECTION
    }
    else{
        Stepper myStepper(stepsPerRevolution, 10, 11,8,9); //SWITCH PINS TO CHANGE DIRECTION
    }
}

void loop() {
  // read the sensor value:
  int sensorReading = 1023; //analogRead(A0); //assuming analogRead returns values from 0 to 1023
  Serial.print(analogRead(A0));
  Serial.print("\n");
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed); //setSpeed only take a positive number
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
  delay(1000);
  flipDir();

}
