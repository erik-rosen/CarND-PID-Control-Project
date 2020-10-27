# Self driving car: PID control project
This repository contains a working PID controller for the Self-Driving Car Engineer Nanodegree Program. Two separate PID controllers control the steering angle and throttle of a car to safely navigate it around a track:

![alt text](pid.gif "PID controllers driving the car around a simulated track")

---

## PID tuning

I chose to manually tune the controllers as I was able to find good-enough parameters fairly quickly by just simple trial and error. I started by first setting the target speed to 30 mph for the throttle controller. The initial values for the throttle controller resulted in a stable controller with good enough performance, so I moved on to tune the steering angle controller. 

I started by adjusting the `Kp` variable to a value where the steering angle controller was marginally stable (oscillations around the center lane did not grow in amplitude) while the controller could handle the sharpest turns without the car driving off the track. I then proceeded to increase the `Kd` parameter until the oscillations and overshoots around the track centre were small. Finally, I set the `Ki` parameter to a low number - the value I started with turned out to be low enough to compensate for biases in the system without affecting the stability or the performance of the controller noticeably. This resulted in a set of controllers which successfully drive the car around the track in a safe manner.

Changing the individual parameters independently generally has the following effect on the system:

Increasing `Kp`:
* Decrease in rise time (time until it get to the target state)
* Increase in overshoot
* Some decrease in steady state error
* Degradation of stability

Increasing `Kd`:
* Decrease in overshoot
* Decrease in settling time (settles faster)
* Improved stability

Increasing `Ki`:
* Decrease in the rise time
* Increase in overshoot
* Increase in settling ime (takes longer to settle)
* Elimination of steady state errors
* Degradation of stability





## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)
