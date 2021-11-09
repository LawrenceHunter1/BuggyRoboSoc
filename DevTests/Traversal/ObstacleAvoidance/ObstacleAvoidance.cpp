#include"buggy.h"
#include"head.h"
#include"motors.h"
#include<arduino.h>

Servo servo;
Head head = Head(2, 3);
Motor leftMotor = Motor(6, 10, LEFT);
Motor rightMotor = Motor(9, 11, RIGHT);
UnifiedMotor uMotor = UnifiedMotor(&leftMotor, &rightMotor);
Buggy buggy = Buggy(&uMotor, &head);

void setup() {
    
}

void loop() {
    
}