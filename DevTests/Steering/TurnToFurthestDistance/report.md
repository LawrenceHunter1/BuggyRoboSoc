# MoveDistanceFromSensor

## Description

### Goal
Using the unified motor and head find the furthest distance in sight and rotate to point towards it.

### Method
Check distance every one degree if greater store the new value then pass the degrees to unified motor turn functions.

### Expected behaviour
Perform 181 steps checking distance each time then turn left or right to point towards furthest distance.

### Setup
Full arduino setup with ultrasonic sensor attached to servo, dual motors.

## Result
- [x] Compile
- [x] Upload
- [x] Runs
- [x] Action performed
- [x] Expected behaviour
- [x] Successful

### Behaviour
1. Buggy head rotates 181 times
2. Buggy begins turning towards the furthest point
3. Buggy turns
4. Buggy idles