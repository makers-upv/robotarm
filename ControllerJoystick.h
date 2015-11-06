// Joystick controller
#ifndef Joystick_h
#define Joystick_h

#include "Arduino.h"


class Joystick {
  public:
    
    // The serial number for the controller
    int id = 1;
    
    // The ids for each part. This is common for all of the controllers
    int shoulder = 0;
    int elbow = 1;
    int wrist = 2;
    
    // Pins for each of the parts
    int shoulderPin = 2;
    int elbowPin = 5;
    int wristPin = 8;
    
    // Read the serial number for the controller
    int init();
    
    // Read a part from the joystick
    int read(int part);
  
  // Methods for this specific controller
  private:
    
    int readPot(int pin);
    
    int readButton(int button);
};

#endif
