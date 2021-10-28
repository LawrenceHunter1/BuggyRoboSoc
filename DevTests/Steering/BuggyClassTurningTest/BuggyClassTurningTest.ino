#include "head.h"
#include "motors.h"
#include "buggy.h"
#include "Servo.h"

Servo servo;
Head head = Head(2, 3);
Motor leftMotor = Motor(6, 10, LEFT);
Motor rightMotor = Motor(9, 11, RIGHT);
UnifiedMotor uMotor = UnifiedMotor(&leftMotor, &rightMotor);
Buggy buggy = Buggy(&uMotor, &head);


void setup() {
    delay(5000);
    servo.attach(12);
    head.setServo(&servo);
    head.rotate(0);
    // Serial monitor
    Serial.begin(9600);
    Serial.println("Buggy test class");
}

void loop() {
    Serial.println("Furthest point");
    buggy.turnToFurthestPoint();
    Serial.println("Nearest point");
    buggy.turnToNearestPoint();
    Serial.println("Furthest point optimal");
    buggy.turnToFurthestPointOpt();
    Serial.println("Nearest point optimal");
    buggy.turnToNearestPointOpt();

    while (true) {}
}