// Controll a simple Robot Arm from a Joystick
// @author Francisco Presencia Fandos & Germán Torres Royo

// Arm variables
#include <Servo.h>
#include "Arm.h"
#include "Controller.h"


// Define the arm
Arm arm;
Controller ctrl;


// The pin for each of the arm's servos
int shoulder = 6;
int elbow = 9;
int wrist = 19;


// Init script for the whole arduino
void setup() {
  
  // Initialize the controller that we want to use
  int controller = ctrl.joystick.init();
  // int controller = ctrl.accelerometer.init();
  // int controller = ctrl.internet.init();
  // ...
  
  // Define the controller as a joystick
  ctrl.init(controller);
  
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
  
  // // Get the new shoulder position and move it
  // shoulderPos += getDelta(pinX, shoulderPos);
  // shoulder.write(shoulderPos);
  // 
  // // Obtain the elbow position and move it
  // elbowPos += getDelta(pinY, elbowPos);
  // elbow.write(elbowPos);
  // 
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
//  * Obtains the current position of the servo
//  * @param pin the current value must be read from here
//  * @param old the old value
//  * @return int the de delta change expected
//  */
// int getDelta(int pin, int old) {
//   
//   // reads the value of the variable resistor
//   int raw = analogRead(pin);
//   int current = map(raw, 0, 1024, 20, 160);
//   int ret = 0;
//   
//   // Small pause needed not to read the same value twice
//   delay(pause);
//   
//   // If we are increasing and the new position won't overflow
//   if (current > 100 && old < 160) {
// 	ret = delta;
// 	}
//   
//   // If we are decreasing and the new pos won't be below 0
//   else if (current < 80 && old > 20) {
// 	ret = -delta;
// 	}
//   
//   // No change expected
//   return ret;
//   }
// 
// 
// /**
//  * Check whether the pin is pressed or not
//  */
// boolean isPressed() {
//   return !digitalRead(pushPin);
//   }
// 
// 
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
// 
// 
// /**
//  * Close the claw by moving the wrist servo
//  */
// void openClaw () {
//   wristPos = wristOpenPos;
//   wrist.write(wristPos);
//   delay(100);
//   }

