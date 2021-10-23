# MoveSetDistance

## Description

### Goal
Using the ultrasonic sensor and motors move 10cm forward.

### Method
Get an initial distance then repeatedly call the `checkDistance()` function of `head` until the returned value is > `init_distance - x` .

### Expected behaviour
Nothing for 5s. Both motors rotate anti-clockwise until an object has moved 10cm closer. Then stop.

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
    > Driving 10cm
3. Both motors start spinning clockwise
4. Motors spin continuously until object is moved 10cm closer
5. Once object is placed motors immediately stop and bugg outputs to serial
    > Drove 10cm
6. Buggy then idles