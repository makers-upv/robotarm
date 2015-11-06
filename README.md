# Robot Arm

A simple Arduino robotic arm. It has 3 [Degrees of Freedom](https://en.wikipedia.org/wiki/Degrees_of_freedom_%28mechanics%29), which allows anyone to controll it with a simple Joystick. They are:

- Shoulder: horizontal rotational axis that moves the whole arm
- Elbow: horizontal rotational axis that moves half of the arm
- Wrist: open/close action


## Getting started

Clone the repository with [git]() or download it:

```bash
git clone git@github.com:makers-upv/robotarm.git
```

Inside the newly created folder, you have to access `robotarm.ino`. Modify the controller method and the pins for the servos:

```c
// ...

// Define the type of the controller
Joystick ctrl;
// Accelerometer ctrl;
// Internet ctrl;
// others...

// The pin for each of the arm's servo
int shoulder = 6;
int elbow = 9;
int wrist = 19;
```


## Author

[Francisco Presencia Fandos](https://github.com/FranciscoP) and German Torres Royo as a [Makers UPV](http://makersupv.com/) project.


## License

MIT License.

The MIT License is a free software license originating at the Massachusetts Institute of Technology (MIT).[1] It is a permissive free software license, meaning that it permits reuse within proprietary software provided all copies of the licensed software include a copy of the MIT License terms and the copyright notice. Such proprietary software retains its proprietary nature even though it incorporates software under the MIT License. The license is also GPL-compatible, meaning that the GPL permits combination and redistribution with software that uses the MIT License.
