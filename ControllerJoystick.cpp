// Joystick controller
// Read several potentiometers and do some action with them
#include "Arduino.h"
#include "ControllerJoystick.h"


// Identify the controller
int Joystick::init(){
  
  return id;
}

// Read a specified part of the controller
int Joystick::read(int id){
  
  if (id == this->shoulder){
    return this->readPot(shoulderPin);
  }
  
  if (id == this->elbow){
    return this->readPot(elbowPin);
  }
  
  if (id == this->wrist){
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