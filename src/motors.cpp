#include "motors.h"
#include <arduino.h>

Motor::Motor(int pin1, int pin2, Position p) {
    _pin1 = pin1;
    pinMode(_pin1, OUTPUT);
    _pin2 = pin2;
    pinMode(_pin2, OUTPUT);
    _position = p;
    Serial.print(p);
    Serial.println(" MOTOR - CREATED");
}

void Motor::moveForward() {
    digitalWrite(_pin1, HIGH);
    digitalWrite(_pin2, LOW);
    Serial.print(_position);
    Serial.println(" MOTOR - MOVE FORWARD");
}

void Motor::moveBackward() {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, HIGH);
    Serial.print(_position);
    Serial.println(" MOTOR - MOVE BACKWARD");
}

void Motor::stop() {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);
    Serial.print(_position);
    Serial.println(" MOTOR - STOP");
}

Position Motor::getPosition() {
    return _position;
}

UnifiedMotor::UnifiedMotor(Motor *leftMotor, Motor *rightMotor) {
    _leftMotor = leftMotor;
    _rightMotor = rightMotor;
    Serial.println("UNIFIED MOTOR - CREATED");
}

void UnifiedMotor::moveForward() {
    _leftMotor->moveForward();
    _rightMotor->moveForward();
    Serial.println("UNIFIED MOTOR - MOVE FORWARD");
}

void UnifiedMotor::moveBackward() {
    _leftMotor->moveBackward();
    _rightMotor->moveBackward();
    Serial.println("UNIFIED MOTOR - MOVE BACKWARD");
}

void UnifiedMotor::stop() {
    _leftMotor->stop();
    _rightMotor->stop();
    Serial.println("UNIFIED MOTOR - STOP");
}

void UnifiedMotor::turnLeft(float theta) {
    Serial.println("UNIFIED MOTOR - TURN LEFT");
    _leftMotor->moveForward();
    delay(2475*(theta/360.0));
    _leftMotor->stop();
}

void UnifiedMotor::turnRight(float theta) {
    Serial.println("UNIFIED MOTOR - TURN RIGHT");
    _rightMotor->moveForward();
    delay(2475*(theta/360.0));
    _rightMotor->stop();
}