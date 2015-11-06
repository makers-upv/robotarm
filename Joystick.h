// Joystick controller
// Read several potentiometers and do some action with them
#ifndef Joystick_h
#define Joystick_h

#include "Arduino.h"
#include "Controller.h"


// Handle the input from a Joystick and extend the controller's methods
class Joystick : public Controller {
  
  public:
    
    // Pins for each of the parts of the joystick
    int shoulderPin = 2;
    int elbowPin = 5;
    int wristPin = 8;
    
    // Read the data for some of the arm parts
    int read(int part);
    
  // Methods for this specific controller
  private:
    
    int readPot(int pin);
    
    int readButton(int button);
};


// Read a specified part of the controller
int Joystick::read(int part){
  
  if (part == this->shoulder){
    return this->readPot(shoulderPin);
  }
  
  if (part == this->elbow){
    return this->readPot(elbowPin);
  }
  
  if (part == this->wrist){
    return this->readButton(wristPin);
  }
}

int Joystick::readPot(int pin){
  int value = analogRead(pin);
  return map(value, 0, 1024, 20, 160);
}

int Joystick::readButton(int pin){
  if(digitalRead(pin))
    return 160;
  else
    return 20;
}


#endif
