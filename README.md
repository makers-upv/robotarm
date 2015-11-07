# Robot Arm

An robot arm made with arduino. It uses different input controllers to move it.


## Getting started

Clone the repository with [git](https://git-scm.com/downloads) (or download it):

```bash
git clone git@github.com:makers-upv/robotarm.git
```

Inside the newly created folder, you have to access `robotarm.ino`. Modify the type of controller that you want and the pins for the servos in this part of the code:

```c
// Define the type of the controller
#include "Joystick.h"
// #include "Accelerometer.h"
// #include "Internet.h"
// ...

// ...

// Initialize the type of controller that we want
Joystick ctrl;
// Accelerometer ctrl;
// Internet ctrl;
// ...

// The pin for each of the arm's servo
int shoulder = 6;
int elbow = 9;
int wrist = 19;
```

Compile, upload and assemble the pieces. You are ready to go!



## Creating a Controller

Any Controller should extend `BaseController` (inside `Controller.h`) and they should implement `int read();`.

If you want to add a servo to the arm, you'll have to implement a new function on each controller and add it to the pins. Say that we want to add `base` to rotate the base. Then we'd need to add this to `robotarm.ino`:

```c
// The pin for each of the arm's servos
int shoulder = 6;
int elbow = 8;
int base = 10;    // NEW
int wrist = 9;
```

Add this to the `setup()`:

```c
// Initialize the parts of the arm
arm.init(shoulder, 90);
arm.init(elbow, 90);
arm.init(base, 90);    // NEW
arm.init(wrist, 120);
```

Last add this to the `loop()`:

```c
arm.move(shoulder, ctrl.read(ctrl.shoulder));
arm.move(elbow, ctrl.read(ctrl.elbow));
arm.move(elbow, ctrl.read(ctrl.base));     // NEW (a simple map from potentiometer->angle)
arm.move(wrist, ctrl.toggle(ctrl.wrist, arm.read(wrist)));
```

As you can see, there's still a missing variable, `ctrl.base`, that we haven't set yet. To set it you'd have to open `Joystick.h` and add the pin that is attached to that potentiometer to the constructor (if it's a potentiometer):

```c
// Pins for each of the joystick controllers
Controller::Controller(){
  pins[this->shoulder] = 2;
  pins[this->elbow] = 3;
  pins[this->base] = 4;    // NEW
  pins[this->wrist] = 5;
}
```



## Author

[Francisco Presencia Fandos](https://github.com/FranciscoP) and German Torres Royo as a [Makers UPV](http://makersupv.com/) project.


## License

MIT License.

The MIT License is a free software license originating at the Massachusetts Institute of Technology (MIT).[1] It is a permissive free software license, meaning that it permits reuse within proprietary software provided all copies of the licensed software include a copy of the MIT License terms and the copyright notice. Such proprietary software retains its proprietary nature even though it incorporates software under the MIT License. The license is also GPL-compatible, meaning that the GPL permits combination and redistribution with software that uses the MIT License.
