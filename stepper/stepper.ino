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

/************GLOBAL VARIABLES**********/
int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution

// for your motor
bool direction = true; //true for ccw, false cw
bool isNano = false; //change depending on your device

//default pins are for a regular arduino. CW rotation.
int pin1 = 8, pin2 = 9, pin3 = 10, pin4 = 11; //pins 8-11: red green yellow blue

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, pin1, pin2, pin3, pin4);

int stepCount = 0;  // number of steps the motor has taken

/*********END OF GLOBAL VARIABLES*******/

void setup() {
  // nothing to do inside the setup
  Serial.begin(9600);
  changeDevice(isNano);
}

//this fxn only changes the pin numbers if you're using a nano
void changeDevice(bool isNano) {
    if(isNano) { //add your pin numbers here
      /*
      pin1 = ;
      pin2 = ;
      pin3 = ;
      pin4 = ;
      */
    }
}

void flipDir(){
  stepsPerRevolution *= -1;
}

void loop() {
  int timeElapsed = millis();
  
  int sensorReading = 1023;

  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed); //setSpeed only take a positive number
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
  //delay(1000);
  //flipDir();

  //Check if timeElapsed is a multiple of 1000ms, plus or minus 100ms
  //Note: motor won't always swap directions every 1000ms because the code might be executing
  //another line in the loop when timeElapsed gets to a multiple of 1000
  if((timeElapsed % 1000) == 0)
    flipDir();
  
}
