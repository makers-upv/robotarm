// Controller header
// Use this to extend and initialize other controllers
#ifndef Controller_h
#define Controller_h

#include "Arduino.h"

class Controller {
  
  public:
    
    // The parts that the arm has. They are different form the pin number since
    // it might not even be a pin or it might be a completely abstract function
    int shoulder = 0;
    int elbow = 1;
    int wrist = 2;
    // ...
    // ...
    
    // Initializes the controller. This can be extended or not, whatever you prefer
    int init();
    
    // Abstract class that has to be initialized to read data from the part
    virtual int read(int part) = 0;
};

int Controller::init(){
  return 1;
}

#endif
