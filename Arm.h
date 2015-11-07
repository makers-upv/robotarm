// Arm header
// Define the methods to move a robot arm with some servos
#include <Servo.h>
#include "Arduino.h"

class Arm {
  public:
    
    // Ammount of degrees that it moves on each cycle
    int delta;
    
    Arm();
    
    // Initialize a servo and move it to the init position
    void init(int pin, int pos);
    
    // Move a servo to the required position
    void move(int pin, int pos);
    
    // Get the current position of an arm
    int read(int pin);
  
  private:
    
    // The number of defined servos has to be as large as the number of pins
    // that an Arduino can have. It's okay if there's "empty" servos
    Servo servo[20];
    
    // Get the next value from the current one
    int next(int prev, int next);
};



Arm::Arm(){
  delta = 3;
}

// Attach the corresponding servo and move it to the desired position
void Arm::init(int pin, int pos){
  servo[pin].attach(pin);
  move(pin, pos);
}

// Move the servo to the required position
void Arm::move(int pin, int goal){
  int prev = this->read(pin);
  int next = this->next(prev, goal);
  servo[pin].write(next);
}

// Move the servo to the required position
int Arm::read(int pin){
  return servo[pin].read();
}


// Receives the position where we want to go and return the delta to move
//   @param prev the old value of the servo
//   @param next the value where we want to get
//   @return int the ammount that we need to move (bounded)
int Arm::next(int prev, int next){
    
  // Increasing the position if we don't overflow
  if (next > prev) {
  	return min(prev + delta, 160);
  	}
  
  // Decreasing the position if we don't underflow
  else if (next < prev) {
  	return max(prev - delta, 20);
  	}
  
  // No change expected
  return prev;
}

