# MoveSetDistance

## Description

### Goal
Using the new actionstack class perform two actions then revert both of them.

### Method
Perform one rotation and one move then call the undo method to move back and rotate back

### Expected behaviour
Nothing for 5s. Buggy turns 30 degrees left, moves 10cm then moves back 10cm and rotates 30 degrees right

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
1. Buggy rotates head to middle. 
2. Buggy writes to serial 
    > Turn to 60 degrees
3. Buggy turns 30 degrees left
4. Buggy writes to serial 
    > Move 10cm
5. Motors spin continuously until object is moved 10cm closer
6. Motors spin continuously until object is moved 10cm further
7. Buggy turns 30 degrees right
8. Buggy then idles