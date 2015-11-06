// Arm source
// Provide the methods to move a robot arm with some servos

#include "Arduino.h"
#include "Controller.h"


// Attach the corresponding servo and move it to the desired position
void Controller::init(int id){
  active = id;
}

// Read a specified part of the controller
int Controller::read(int part){
  
  if (active == joystick.id)
    return joystick.read(part);
  
  // if (active == accelerometer.id)
  //   return accelerometer.read(part);
  // 
  // if (active == internet.id)
  //   return internet.read(part);
  
  // ...
  // ...
  
  return 0;
}
