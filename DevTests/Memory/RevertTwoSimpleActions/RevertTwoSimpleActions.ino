#include "head.h"
#include "motors.h"
#include "buggy.h"
#include <Servo.h>

Servo servo;
Head head = Head(2, 3);
Motor leftMotor = Motor(6, 10, LEFT);
Motor rightMotor = Motor(9, 11, RIGHT);
UnifiedMotor uMotor = UnifiedMotor(&leftMotor, &rightMotor);
Buggy buggy = Buggy(&uMotor, &head);


void setup() {
    // delay(1000);
    servo.attach(12);
    head.setServo(&servo);
    head.rotate(90);
    // Serial monitor
    Serial.begin(9600);
    Serial.println("------------------------------");
    Serial.println("------------------------------");
    Serial.println("------------------------------");
    Serial.println();
    Serial.println();
    Serial.println("Buggy test class");
}

void loop() {
    Serial.println("Turn to 60 degrees");
    buggy.turn(60.0);
    delay(1000);
    Serial.println("Move 10cm");
    buggy.move(5.0);
    delay(1000);
    buggy.undo(2);
    Serial.println("EXITING");
    delay(1000);
    exit(0);
}