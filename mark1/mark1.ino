/**
 * Controll a simple Robot Arm from a Joystick
 * @author Francisco Presencia Fandos
 */

// Needed libraries
#include <Servo.h>

// Arm variables
Servo shoulder;
int shoulderPin = 9;
int shoulderPos = 90;

Servo elbow;
int elbowPin = 10;
int elbowPos = 90;

Servo wrist;
int wristPin = 11;
int wristPos = 90;

// Joystick variables
int pinX = 1;
int pinY = 0;
int valueX = 0;
int valueY = 0;

// Speed variables. Note: they are inversely proportional
int pause = 30;
int delta = 5;

bool debug = false;


/**
 * Init script for the whole arduino
 * Make the communication and servo begin
 */
void setup() {
  
  if (debug) {
    // Begin communication
    Serial.begin(9600);
    }
  
  // Start the servo
  shoulder.attach(shoulderPin);
  elbow.attach(elbowPin);
  wrist.attach(wristPin);
  }



/**
 * Perform this over and over again
 */
void loop() {
  
  // Debug script
  if (debug) {
    Serial.println(elbowPos);
    Serial.println(shoulderPos);
    Serial.println();
    }
  
  // Get the new shoulder position and move it
  shoulderPos += getDelta(pinX, shoulderPos);
  shoulder.write(shoulderPos);
  
  // Obtain the elbow position and move it
  elbowPos += getDelta(pinY, elbowPos);
  elbow.write(elbowPos);
  
  // Get the click action and perform the action
  wrist.write(wristPos);
  }



/**
 * Obtains the current position of the servo
 * @param pin the current value must be read from here
 * @param old the old value
 * @return int the de delta change expected
 */
int getDelta(int pin, int old) {
  
  // reads the value of the variable resistor
  int raw = analogRead(pin);
  int cur = map(raw, 0, 1024, 20, 160);
  int ret = 0;
  
  // Small pause needed not to read the same value twice
  delay(pause);
  
  // If we are increasing and the new position won't overflow
  if (cur > 100 && old < 160) {
    ret = delta;
    }
  
  // If we are decreasing and the new pos won't be below 0
  else if (cur < 80 && old > 20) {
    ret = -delta;
    }
  
  // No change expected
  return ret;
  }
