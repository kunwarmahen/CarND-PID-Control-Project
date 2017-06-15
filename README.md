# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Reflection

* Describes the effect of the P, I, D component of the PID algorithm in the implementation

	P (proportional control): Is the steering control in proportion to the cross track error. P in PID helps steer the car towards the line of drive which minimizes CTE. I noticed the higher value of P resulted in very big steering changes, as it tried to correct very aggressively to counter CTE. See the video for reference where  P is higher.  [Video](video/self_driving_car_pid_controller_high_p_low_i_d.mp4)
	
	I (integral control): Is the correction in the steering to mitigate the systematic bias in the vehicle. I found that for the simulator putting higher values of I resulted in system trying to correct the bias (which in case of simulatory is not there) which basically resulted in crash. So I decided to leave the bias nil. See the video which high I.[Video](video/self_driving_car_pid_controller_high_i_low_p_d.mp4)
	
	D (derivative  control): Is the correction to mitigate oscillations of the car around line where there is minimum CTE. This control tries to smooth this oscillation. I found out that higher the D values more smooth the car drove. For higher speed it made a quite a difference. Following video shows the high oscillation when the system is set to lower D.[Video](video/self_driving_car_pid_controller_high_p_d_low_i.mp4)


* Discusses how I chose the final hyperparameters (P, I, D coefficients). This could be have been done through manual tuning, twiddle, SGD, or something else, or a combination!

	I tried twiddle approach and even wrote the code but I faced challenges when I tried to tune the coefficient values. The moment the system tries to tune it using twiddle, car crashes and eventaully I had to give it up. Finally I decided to manually tune the hyper parameters with hit and try. As discussed above I kept low value of P, zero I and high value of D.  Following video shows the system running with final value of P=0.15, I=0, D=0.99 [Video](video/self_driving_car_pid_controller_final_param.mp4)
## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
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

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
