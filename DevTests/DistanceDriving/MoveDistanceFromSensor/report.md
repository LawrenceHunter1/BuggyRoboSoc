# MoveDistanceFromSensor

## Description

### Goal
Using the ultrasonic sensor and motors move towards an object stopping 30cm infront.

### Method
Get an initial distance then repeatedly call the `checkDistance()` function of `head` until the returned value is <= 30.

### Expected behaviour
Nothing for 5s. Both motors rotate anti-clockwise until an object is within 30cm. Then stop.

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
    > Driving towards a wall and NOT hitting it!
3. Both motors start spinning clockwise
4. Motors spin continuously until object is placed within 30cm 
5. Once object is placed motors immediately stop and bugg outputs to serial
    > Within 30cm of wall.
6. Buggy then idles