// Controll a simple Robot Arm from a Joystick
// @author Francisco Presencia Fandos & Germán Torres Royo

// Arm variables
#include <Servo.h>
#include "Arm.h"

// Define the type of the controller
#include "Joystick.h"
// #include "Accelerometer.h"
// #include "Internet.h"
// ...


// Define the object to handle the arm
Arm arm;

// Initialize the type of controller that we want
Joystick ctrl;
// Accelerometer ctrl;
// Internet ctrl;
// ...


// The pin for each of the arm's servos
int shoulder = 6;
int elbow = 8;
int wrist = 9;


// Init script for the whole arduino
void setup() {
  
  // Initialize the parts of the arm
  arm.init(shoulder, 90);
  arm.init(elbow, 90);
  arm.init(wrist, 120);
}


// Perform this over and over again
void loop() {
  
  arm.move(shoulder, ctrl.read(ctrl.shoulder));
  arm.move(elbow, ctrl.read(ctrl.elbow));
  arm.move(wrist, ctrl.toggle(ctrl.wrist, arm.read(wrist)));
  
  delay(10);
}
