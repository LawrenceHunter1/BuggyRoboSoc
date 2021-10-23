#include "head.h"
#include "motors.h"
#include "Servo.h"

Servo servo;
Head head = Head(2, 3);
Motor leftMotor = Motor(6, 10, LEFT);
Motor rightMotor = Motor(9, 11, RIGHT);
UnifiedMotor uMotor = UnifiedMotor(&leftMotor, &rightMotor);

// Move xcm
long x = 10;

void setup() {
    // delay(5000);
    servo.attach(12);
    head.setServo(&servo);
    head.initialise();
    // Serial monitor
    Serial.begin(9600);
    Serial.print("Driving ");
    Serial.print(x);
    Serial.println("cm");
}

void loop() {
    delay(100);
    long init_distance = head.checkDistance();
    uMotor.moveForward();
    while(head.checkDistance() > init_distance - x){
        delay(15);
    }
    uMotor.stop();
    Serial.print("Drove ");
    Serial.print(x);
    Serial.println("cm");
    delay(15);
    exit(0);
}
