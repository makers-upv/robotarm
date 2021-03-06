// Controller
// Use this to extend and initialize other controllers
#include "Arduino.h"

class Controller {
  
  public:
    
    Controller();
    
    // The parts that the arm has. They are different form the pin number since
    // it might not even be a pin or it might be a completely abstract function
    int shoulder;
    int elbow;
    int wrist;
    // ...
    
    // Abstract class that has to be initialized to read data from the part
    virtual int read(int part) = 0;
};

Controller::Controller(){
  shoulder = 0;
  elbow = 1;
  wrist = 2;
}