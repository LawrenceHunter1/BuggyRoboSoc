# MoveDistanceFromSensor

## Description

### Goal
Using the unified motor be able to turn approximately x degrees left or right.

### Method
Use the unified motor with delays to turn with an input angle theta scaling the time delay.

### Expected behaviour
Turn approximately 180 degrees left, wait 5 seconds, then turn approximately 180 degrees right.

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
1. Buggy turns close to 180 degrees left
2. Buggy waits 5 seconds
3. Buggy turns close to 180 degrees right
4. Buggy then idles