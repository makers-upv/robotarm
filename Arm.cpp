// Arm source
// Provide the methods to move a robot arm with some servos

#include "Arduino.h"
#include "Arm.h"

// Initialize the arm
Arm::Arm() {
}

// Attach the corresponding servo and move it to the desired position
void Arm::init(int pin, int pos){
  servo[pin].attach(pin);
  move(pin, pos);
}

// Move the servo to the required position
void Arm::move(int pin, int pos){
  int cur = servo[pin].read();
  cur = this->delta(cur, pos);
  servo[pin].write(cur);
}

int Arm::delta(int prev, int next){
  
  int ang = 3;
  
  // If we are increasing and the new position won't overflow
  if (next > 100 && prev < 160) {
  	return ang;
  	}
  
  // If we are decreasing and the new pos won't be below 0
  else if (next < 80 && prev > 20) {
  	return -ang;
  	}
  
  // No change expected
  return 0;
}
