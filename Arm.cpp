// Arm source
// Provide the methods to move a robot arm with some servos

#include "Arduino.h"
#include "Arm.h"


// Attach the corresponding servo and move it to the desired position
void Arm::init(int pin, int pos){
  servo[pin].attach(pin);
  move(pin, pos);
}

// Move the servo to the required position
void Arm::move(int pin, int goal){
  int prev = servo[pin].read();
  int next = prev + this->diff(prev, goal);
  servo[pin].write(next);
}


// Receives the position where we want to go and return the delta to move
//   @param prev the old value of the servo
//   @param next the value where we want to get
//   @return int the ammount that we need to move (bounded)
int Arm::diff(int prev, int next){
    
  // Increasing the position if we don't overflow
  if (next > prev && prev + delta < 160) {
  	return delta;
  	}
  
  // Decreasing the position if we don't underflow
  else if (next < prev && prev - delta > 20) {
  	return -delta;
  	}
  
  // No change expected
  return 0;
}
