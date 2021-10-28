#include "head.h"
#include "motors.h"
#include "Servo.h"

Servo servo;
Head head = Head(2, 3);
Motor leftMotor = Motor(6, 10, LEFT);
Motor rightMotor = Motor(9, 11, RIGHT);
UnifiedMotor uMotor = UnifiedMotor(&leftMotor, &rightMotor);

void setup() {
    delay(5000);
    servo.attach(12);
    head.setServo(&servo);
    head.rotate(0);
    // Serial monitor
    Serial.begin(9600);
    Serial.println("Directing to furthest distance");
}

void loop() {
    int angle = -1;
    int min = 32767;
    for (int i = 0; i <= 180; i++) {
        head.rotate(i);
        delay(10);
        int distance = head.checkDistance();
        if (distance < min) {
            min = distance;
            angle = i;
        }
    }
    if (angle > 90) {
        uMotor.turnLeft(float(angle-90));
    } else if (angle < 90) {
        uMotor.turnRight(float(90-angle));
    }
    exit(0);
}
