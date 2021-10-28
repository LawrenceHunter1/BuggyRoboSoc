#include "head.h"
#include <Arduino.h>
#include "Servo.h"

Head::Head(int echo, int trig) {
    _echo = echo;
    pinMode(_echo, INPUT);

    _trig = trig;
    pinMode(_trig, OUTPUT);

    Serial.println("HEAD - CREATED");
}

void Head::initialise() {
    _servo->write(90);
    delay(100);
    Serial.println("HEAD - INITIALISED");
}

long Head::checkDistance() {
    long duration;
    int distance;
    // Clears condition
    digitalWrite(_trig, LOW);
    delayMicroseconds(2);

    // Sets trig pin high
    digitalWrite(_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig, LOW);

    // Reads the echoPin
    duration = pulseIn(_echo, HIGH);
    // Calculates distance
    distance = duration * 0.034 / 2; // Speed of sound
    return distance;
}

void Head::rotate(long angle) {
    _servo->write(angle);
    delay(100);
}

int Head::getEchoPin() {
    return _echo;
}

int Head::getTrigPin() {
    return _trig;
}

Servo* Head::getServo() {
    return _servo;
}

void Head::setServo(Servo* servo) {
    _servo = servo;
}