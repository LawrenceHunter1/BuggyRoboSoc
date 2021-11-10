#include "motors.h"
#include <arduino.h>

// Sets the pins used
Motor::Motor(int pin1, int pin2, Position p) {
    _pin1 = pin1;
    pinMode(_pin1, OUTPUT);
    _pin2 = pin2;
    pinMode(_pin2, OUTPUT);
    _position = p;
}

// Sets the pin high spinning the wheel forward
void Motor::moveForward() {
    digitalWrite(_pin1, HIGH);
    digitalWrite(_pin2, LOW);
}

// Sets the pin high spinning the wheel backward
void Motor::moveBackward() {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, HIGH);
}

// Sets the pins low stopping the wheel
void Motor::stop() {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);
}

// gets the enum position 
Position Motor::getPosition() {
    return _position;
}

// sets pointers for both motors 
UnifiedMotor::UnifiedMotor(Motor *leftMotor, Motor *rightMotor) {
    _leftMotor = leftMotor;
    _rightMotor = rightMotor;
    Serial.println("UNIFIED MOTOR - CREATED");
}

// calls moveforward on both motors
void UnifiedMotor::moveForward() {
    _leftMotor->moveForward();
    _rightMotor->moveForward();
    Serial.println("UNIFIED MOTOR - MOVE FORWARD");
}

// calls movebackward on both motors
void UnifiedMotor::moveBackward() {
    _leftMotor->moveBackward();
    _rightMotor->moveBackward();
    Serial.println("UNIFIED MOTOR - MOVE BACKWARD");
}

// calls stop on both motors
void UnifiedMotor::stop() {
    _leftMotor->stop();
    _rightMotor->stop();
}

// Based on the angle performs an approximate
// user calculated time delay scalling
// calling left motor to move forward
// for the duration then stopping
void UnifiedMotor::turnRight(double theta) {
    _leftMotor->moveForward();
    delay(2475*(theta/360.0));
    _leftMotor->stop();
}

// Based on the angle performs an approximate
// user calculated time delay scalling
// calling right motor to move forward
// for the duration then stopping
void UnifiedMotor::turnLeft(double theta) {
    _rightMotor->moveForward();
    delay(2475*(theta/360.0));
    _rightMotor->stop();
}

// returns a pointer to the left motor
Motor* UnifiedMotor::getLeftMotor() {
    Serial.println("UNIFIED MOTOR - GET LEFT MOTOR");
    return _leftMotor;
}

// returns a pointer to the right motor
Motor* UnifiedMotor::getRightMotor() {
    Serial.println("UNIFIED MOTOR - GET RIGHT MOTOR");
    return _rightMotor;
}