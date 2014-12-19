/**
 * Arm
 * Gives public methods to control the robot arm
 */
class Arm {
  // Methods available for the loop
  public:
    Arm();
    void rest();
    void up(int distance, boolean relative);
    void side(int distance, boolean relative);
    void forward(int distance, boolean relative);
  };



/**
 * Initializes the robot arm
 */
Arm::Arm() {

  // Set the arm to the resting position
  this->rest();

  // TODO: create here the servo controls

  // Inform of the current status
  Serial.println("Arm ready to go");
  }



/**
 * Set the arm to a resting position
 */
void Arm::rest() {

  // Set the resting position for all of the servos
  // TODO: stop them from being global variables
  shoulder.write(90);
  elbow.write(90);
  wrist.write(90);

  // Inform of the current status
  Serial.println("Resting");
  }



void Arm::up(int distance, boolean relative) {

  }

// Private method
void Arm::upDiff();

//void Arm::upDiff();
//void Arm::y();
void Arm::up(int distance);
void Arm::up(int distance, boolean relative);
void Arm::upDiff(int distance);




/*
void Arm::up(int distance) {
  if (lastAction == "forwardright")
    {
    Serial.println("Forward Left");
    this->leftForward();
    this->leftDown();
    lastAction = "forwardleft";
    }
  
  else if (lastAction == "forwardleft")
    {
    Serial.println("Forward Right");
    this->rightForward();
    this->rightDown();
    lastAction = "forwardright";
    }
  
  else
    {
    Serial.println("Forward Ready");
    this->toForward();
    lastAction = "forwardright";
    }
  }

void Spider::backward()
  {
  }
  
void Spider::left()
  {
  }

void Spider::right()
  {
  }

void Spider::grab()
  {
  this->idle();
  this->middleForward();
  this->topGrab();
  this->topUp();
  this->topRelease();
  this->idle();
  }

void Spider::tilt()
  {
  }




// PRIVATE
// ---------------------------------------------------------------------------------


// IDLE
// Reset a 90 grados
void Spider::toNinety()
  {
  bottomlefthip.write(90);
  middlelefthip.write(90);
  toplefthip.write(90);
  toprighthip.write(90);
  middlerighthip.write(90);
  bottomrighthip.write(90);
  
  bottomleftknee.write(90);
  middleleftknee.write(90);
  topleftknee.write(45);
  toprightknee.write(135);
  middlerightknee.write(90);
  bottomrightknee.write(90);
  }



// FORWARD
// Get ready to move forward
void Spider::toForward()
  {
  int pos = middlerighthip.read();
  // Get to the point to start movement
  if (pos < 60)
    {
    for(pos; pos < 60; pos += 1)
      {
      // left forward
      toplefthip.write(180 - pos);
      bottomlefthip.write(180 - pos);
      middlerighthip.write(pos);
      
      // right backward
      middlelefthip.write(pos);
      toprighthip.write(180 - pos);
      bottomrighthip.write(180 - pos);
      delay(5);
      }
    }
  else
    {
    for(pos; pos > 60; pos -= 1)
      {
      // left forward
      toplefthip.write(180 - pos);
      bottomlefthip.write(180 - pos);
      middlerighthip.write(pos);
      
      // right backward
      middlelefthip.write(pos);
      toprighthip.write(180 - pos);
      bottomrighthip.write(180 - pos);
      delay(5);
      }
    }
  
  // Left legs up
  for(int pos = 90; pos > 45; pos -= 1)
    {
    topleftknee.write(180 - pos - 45);
    bottomleftknee.write(pos);
    middlerightknee.write(180 - pos);
    delay(10);
    }
  }

// Move left legs forward and right backward
void Spider::leftForward()
  {
  for(int pos = 60; pos < 120; pos += 1)
    {
    // left forward
    toplefthip.write(180 - pos);
    bottomlefthip.write(180 - pos);
    middlerighthip.write(pos);
    
    // right backward
    middlelefthip.write(pos);
    toprighthip.write(180 - pos);
    bottomrighthip.write(180 - pos);
    delay(5);
    }
  }

// Move left legs down and right up
void Spider::leftDown()
  {
  // Left legs down
  for(int pos = 45; pos < 90; pos += 1)
    {
    topleftknee.write(180 - pos - 45);
    bottomleftknee.write(pos);
    middlerightknee.write(180 - pos);
    delay(10);
    }
  
  // Right legs up
  for(int pos = 90; pos > 45; pos -= 1)
    {
    toprightknee.write(pos + 45);
    bottomrightknee.write(180 - pos);
    middleleftknee.write(pos);
    delay(10);
    }
  }

// Las patas izquierdas retroceden
void Spider::rightForward()
  {
  for(int pos = 60; pos <= 120; pos += 1)
    {
    // right forward
    toprighthip.write(pos);
    middlelefthip.write(180 - pos);
    bottomrighthip.write(pos);
    
    // left backward
    toplefthip.write(pos);
    bottomlefthip.write(pos);
    middlerighthip.write(180 - pos);
    delay(10);
    }  
  }

// Move left legs down and right up
void Spider::rightDown()
  {
  // Right legs go down
  for(int pos = 45; pos < 90; pos += 1)
    {
    toprightknee.write(pos + 45);
    bottomrightknee.write(180 - pos);
    middleleftknee.write(pos);
    delay(10);
    }
  
  // Left legs up
  for(int pos = 90; pos > 45; pos -= 1)
    {
    topleftknee.write(180 - pos - 45);
    bottomleftknee.write(pos);
    middlerightknee.write(180 - pos);
    delay(10);
    }
  }



// GRAB
void Spider::middleForward()
  {
  toprighthip.write(110);
  toplefthip.write(80);
  
  for(int pos = 60; pos < 130; pos += 1)
    {
    // Middle go forward
    middlerighthip.write(pos);
    middlelefthip.write(180 - pos);
    
    // Bottom go backward
    bottomlefthip.write(pos);
    bottomrighthip.write(180 - pos);
    delay(10);
    }
  delay(1000);
  }

void Spider::topGrab()
  { 
  for(int pos = 60; pos < 120; pos += 1)
    {
    toprighthip.write(pos + 50);
    toplefthip.write(140 - pos);
    delay(10);
    }
  }

void Spider::topUp()
  {
  for(int pos = 90; pos > 0; pos -= 1)
    {
    toprightknee.write(pos);
    topleftknee.write(180 - pos);
    delay(10);
    }
  }

void Spider::topRelease()
  {
  for(int pos = 120; pos > 60; pos -= 1)
    {
    toprighthip.write(pos + 50);
    toplefthip.write(140 - pos);
    delay(10);
    }
  }

*/
