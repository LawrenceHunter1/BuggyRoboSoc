# MoveDistanceFromSensor

## Description

### Goal
Using the unified motor and head find the furthest distance in sight and rotate to point towards it using fewer checks.

### Method
Check distance every five degrees if greater store the new value narrow down to every one degree in this range then pass the degrees to unified motor turn functions.

### Expected behaviour
Perform 5 degree steps checking distance each time then peform 5 one degree steps then turn left or right to point towards furthest distance.

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
1. Buggy head rotates in steps of 5
2. Buggy head rotates 1 degrees 5 times
3. Buggy begins turning towards the furthest point
4. Buggy turns
5. Buggy idles