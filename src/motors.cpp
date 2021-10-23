#include "motors.h"
#include <arduino.h>

Motor::Motor(int pin1, int pin2, Position p) {
    _pin1 = pin1;
    pinMode(_pin1, OUTPUT);
    _pin2 = pin2;
    pinMode(_pin2, OUTPUT);
    _position = p;
}

void Motor::moveForward() {
    digitalWrite(_pin1, HIGH);
    digitalWrite(_pin2, LOW);
}

void Motor::moveBackward() {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, HIGH);
}

void Motor::stop() {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);
}

Position Motor::getPosition() {
    return _position;
}

UnifiedMotor::UnifiedMotor(Motor *leftMotor, Motor *rightMotor) {
    _leftMotor = leftMotor;
    _rightMotor = rightMotor;
}

void UnifiedMotor::moveForward() {
    _leftMotor->moveForward();
    _rightMotor->moveForward();
}

void UnifiedMotor::moveBackward() {
    _leftMotor->moveBackward();
    _rightMotor->moveBackward();
}

void UnifiedMotor::stop() {
    _leftMotor->stop();
    _rightMotor->stop();
}