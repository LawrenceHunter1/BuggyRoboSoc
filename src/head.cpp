#include "head.h"
#include <Arduino.h>
#include "Servo.h"

// Constructor sets the pins
Head::Head(int echo, int trig) {
    _echo = echo;
    pinMode(_echo, INPUT);

    _trig = trig;
    pinMode(_trig, OUTPUT);

    Serial.println("HEAD - CREATED");
}

// Sets the servo to point normally
void Head::initialise() {
    _servo->write(90);
    delay(10);
    Serial.println("HEAD - INITIALISED");
}

// Uses the sensor pins to output a pulse
// based on time to recieve pulse calculates
// distance using speed of sound
double Head::checkDistance() {
    double duration;
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

// Rotates the servo to the new position
void Head::rotate(double angle) {
    _servo->write(angle);
    delay(50);
}

// Returns the pin used for echo
int Head::getEchoPin() {
    return _echo;
}

// Returns the pin used for trig
int Head::getTrigPin() {
    return _trig;
}

// Returns a pointer to the servo
Servo* Head::getServo() {
    return _servo;
}

// Sets the pin used for the servo
void Head::setServo(Servo* servo) {
    _servo = servo;
}