// Joystick controller
// Read several potentiometers and do some action with them
#include "Arduino.h"
#include "Controller.h"

// Handle the input from a Joystick and extend the controller's methods
class Controller : public BaseController {
  
  public:
    
    Controller();
    
    // Read the data for some of the arm parts
    int read(int part);
    
    int toggle(int part, int prev);
    
  private:
    
    // Pins for each of the parts of the joystick
    int pins[20];
    
    // Read a potentiometer and return its angle
    int readPot(int pin);
    
    // Read a button and return an open or closed angle
    boolean readButton(int pin);
};


// Pins for each of the joystick controllers
Controller::Controller(){
  pins[this->shoulder] = 2;
  pins[this->elbow] = 3;
  pins[this->wrist] = 5;
}


// Read a specified part of the controller
int Controller::read(int part){
  
  // You can check each part with this:
  //if (part == this->shoulder)
  
  return this->readPot(this->pins[part]);
}

int Controller::toggle(int part, int prev){
  
  // Return the previous value if the button is not pressed
  if (!this->readButton(this->pins[this->wrist]))
    return prev;
  
  while(this->readButton(this->pins[this->wrist]));
  
  // If we reach here, the button was pressed. Invert the value
  return prev > 90 ? 20 : 160;
}

int Controller::readPot(int pin){
  return map(analogRead(pin), 0, 1024, 20, 160);
}

boolean Controller::readButton(int pin){
  if(digitalRead(pin))
    return 1;
  
  return 0;
}



// Serial.println(isPressed());
// // Get the click action and perform the action
// if (isPressed()) {
// 	if(wristPos == wristOpenPos)
// 	  closeClaw();
// 	else
// 	  openClaw();
// 	}
//  while(isPressed()); //Debouncing of the input
// 
// wrist.write(wristPos);


// /**
//  * Check whether the pin is pressed or not
//  */
// boolean isPressed() {
//   return !digitalRead(pushPin);
//   }
// 
// /** 
//  * Close the claw by moving the wrist servo
//  */
// void closeClaw() {
//   wristPos = 90;
//   wrist.write(wristPos);
//   delay(100);
//   }
// 
// /**
//  * Close the claw by moving the wrist servo
//  */
// void openClaw () {
//   wristPos = wristOpenPos;
//   wrist.write(wristPos);
//   delay(100);
//   }


