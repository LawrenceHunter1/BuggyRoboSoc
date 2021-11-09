# ObstacleAvoidance

## Description

### Goal
Using the ultrasonic sensor and motors, avoid an object ahead

### Method
Repeatedly check distance straight ahead with `checkDistance()` while motors are activated until a threshold is met. Rotate head, also using `checkDistance()`, until a suitable difference in initial and new distance is met. Activate right motor until facing head rotation. Activate both motors.

### Expected behaviour
Approach an object, rotate until not facing the object, and then drive forward.

### Setup
Full arduino setup with ultrasonic sensor attached to servo, dual motors.

## Result
N/A

### Behaviour
N/A