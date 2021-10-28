#include "head.h"
#include "motors.h"
#include "Servo.h"

Servo servo;
Motor leftMotor = Motor(6, 10, LEFT);
Motor rightMotor = Motor(9, 11, RIGHT);
UnifiedMotor uMotor = UnifiedMotor(&leftMotor, &rightMotor);

void setup() {
    // Serial monitor
    Serial.begin(9600);
    Serial.println("Turning test");
}

void loop() {
    uMotor.turnLeft(180);
    delay(5000);
    uMotor.turnRight(180);
    while (true) {}
}
