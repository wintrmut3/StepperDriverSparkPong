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
#include <math.h>    


/************GLOBAL VARIABLES**********/
int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution (This is correct for our motor)

// for your motor
bool direction = true; //true for ccw, false cw

//default pins are for an arduino uno. CW rotation.
int pin1 = 8, pin2 = 9, pin3 = 10, pin4 = 11; //pins 8-11: red green yellow blue

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, pin1, pin2, pin3, pin4);

int stepCount = 0;  // number of steps the motor has taken
unsigned long time;

/*********END OF GLOBAL VARIABLES*******/

void setup() {
  // nothing to do inside the setup
  Serial.begin(9600);
  time = millis();

}

void flipDir(){
  stepsPerRevolution *= -1;
}

void moveWithVelocity(double vx, double vy){ //probably put into loop fn
  //these variables are multipliers, so we have 1*vx and 1*vy, both being less than 1. This will help for direction
  double angle = atan2(vy,vx);
//  stepsPerRevolutionX=vX; //we'll have 2 motors ideally, one for x and one for y. then, we'll need 2 steps per rev. vars.
}

void loop() {
  
  // motorSpeed should be a range from 0 to 100:
  int motorSpeed = 80;
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed); //setSpeed only takes a positive number
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 200); //we have constant 200 steps per revolution
  }

  if(stepCount % 200 ==0) { //flip direction of rotation every 500 steps
    flipDir();
    Serial.print(millis()-time);
    Serial.print("ms per cycle\n");
    time = millis();
  }
  stepCount++;
}
