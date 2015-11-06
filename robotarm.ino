// Controll a simple Robot Arm from a Joystick
// @author Francisco Presencia Fandos & Germán Torres Royo

// Arm variables
#include <Servo.h>
#include "Arm.h"

#include "Joystick.h"
// #include "Accelerometer.h"
// #include "Internet.h"
// ...


// Define the arm
Arm arm;

// Define the controller. Can be of several types
Joystick ctrl;
// Accelerometer ctrl;   // Controlling it with an accelerometer
// Internet ctrl;        // Controlling it through the internet
// ...


// The pin for each of the arm's servos
int shoulder = 6;
int elbow = 9;
int wrist = 19;


// Init script for the whole arduino
void setup() {
  
  // Initialize the controller
  ctrl.init();
  
  // Pin and initial position in degrees
  arm.init(shoulder, 90);
  arm.init(elbow, 90);
  arm.init(wrist, 90);
}


// Perform this over and over again
void loop() {
  
  arm.move(shoulder, ctrl.read(ctrl.shoulder));
  arm.move(elbow, ctrl.read(ctrl.elbow));
  arm.move(wrist, ctrl.read(ctrl.wrist));
  
  // Serial.println(isPressed());
  // // Get the click action and perform the action
  // if (isPressed()) {
  // 	if(wristPos == wristOpenPos)
  // 	  closeClaw();
  // 	else
  // 	  openClaw();
  // 	}
  //  while(isPressed()); //Debouncing of the input
  // 
  // wrist.write(wristPos);
}


// /**
//  * Check whether the pin is pressed or not
//  */
// boolean isPressed() {
//   return !digitalRead(pushPin);
//   }
// 
// /** 
//  * Close the claw by moving the wrist servo
//  */
// void closeClaw() {
//   wristPos = 90;
//   wrist.write(wristPos);
//   delay(100);
//   }
// 
// /**
//  * Close the claw by moving the wrist servo
//  */
// void openClaw () {
//   wristPos = wristOpenPos;
//   wrist.write(wristPos);
//   delay(100);
//   }

