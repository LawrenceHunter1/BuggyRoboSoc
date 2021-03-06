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
    head.rotate(90);
    // Serial monitor
    Serial.begin(9600);
    Serial.println("Driving towards a wall and NOT hitting it!");
}

void loop() {
    long init_distance = head.checkDistance();
    uMotor.moveForward();
    while(head.checkDistance() > 30){
        delay(15);
    }
    uMotor.stop();
    Serial.print("Within 30cm of wall.");
    delay(100);
    exit(0);
}
