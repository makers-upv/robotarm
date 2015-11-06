// Arm header
// Define the methods to move a robot arm with some servos
#ifndef Arm_h
#define Arm_h

#include <Servo.h>
#include "Arduino.h"

class Arm
{
  public:
    
    Arm();
    
    // Ammount of degrees that it moves on each cycle
    int delta;
    
    // Initialize a servo and move it to the init position
    void init(int pin, int pos);
    
    // Move a servo to the required position
    void move(int pin, int pos);
    
    // Move a servo to the required position
    int read(int pin);
  
  private:
    
    // The number of defined servos has to be as large as the number of pins
    // that an Arduino can have. It's okay if there's "empty" servos
    Servo servo[20];
    
    int diff(int prev, int next);
    
};

#endif
