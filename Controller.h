// Controller header
// This is a thin wrapper for any method that you want to add in your own
// controller, which should be defined inside the folder "controllers"
// When you add one, remember to add here the constructor 
#ifndef Controller_h
#define Controller_h

#include <Servo.h>
#include "Arduino.h"
#include "ControllerJoystick.h"
// #include "ControllerAccelerometer.h"
// #include "ControllerInternet.h"
// ...


class Controller {
  public:
    
    
    // The part of the joystick that we're trying to read right now
    // It's different from the pin since it might not even be a pin
    // or it might be a completely abstract part in the future
    int shoulder = 0;
    int elbow = 1;
    int wrist = 2;
    // ...
    // ...
    
    // Initialize the controller
    void init(int id);
    
    // Read the controller
    int read(int controller);
    
    // Initialize a servo and move it to the init position
    Joystick joystick;
    // Accelerometer accelerometer;
    // Internet internet;
    // ...
    
  private:
    
    // The controller that is active
    int active;
};

#endif
