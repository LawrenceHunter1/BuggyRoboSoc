#include"buggy.h"
#include"head.h"
#include"motors.h"
#include<arduino.h>

#define DISTANCE_THRESHOLD 50
#define DIFFERENCE_THRESHOLD 20
#define ROTATE_INTERVAL 5

Servo servo;
Head head = Head(2, 3);
Motor leftMotor = Motor(6, 10, LEFT);
Motor rightMotor = Motor(9, 11, RIGHT);
UnifiedMotor uMotor = UnifiedMotor(&leftMotor, &rightMotor);
Buggy buggy = Buggy(&uMotor, &head);

void setup() {
    delay(2000);
    servo.attach(12);
    head.setServo(&servo);
    head.rotate(90);
    // Serial monitor
    Serial.begin(9600);
    Serial.println("Avoiding an obstacle");
    delay(3000);
}

void loop() {
    // Approach Object
    long init_distance = head.checkDistance();
    uMotor.moveForward();
    while(head.checkDistance() > DISTANCE_THRESHOLD){
        delay(15);
    }
    uMotor.stop();

    // Look Left and Right
    int angle = checkDifferences();

    if(angle == -1){
        // A direction was not found
        // The robot shakes his head and rolls backwards in shame
        uMotor.moveBackward();
        for(int i = 0; i < 6; i++){
            head.rotate(60);
            delay(30);
            head.rotate(120);
            delay(30);
        }
        uMotor.stop();
        exit(0);
    }
    // Rotate towards the "avoid" direction
    else if(angle >= 90){
        uMotor.turnRight(angle-90);
    }
    else{
        uMotor.turnLeft(90-angle);
    }

    head.rotate(180-angle);
    delay(15);
    uMotor.moveForward();

    // Move until not in way of object
    while(head.checkDistance() - DISTANCE_THRESHOLD < DIFFERENCE_THRESHOLD){
        delay(10);
    }
    head.rotate(90);

    // Reset back to original direction
    if(angle >= 90){
        uMotor.turnLeft(angle-90);
    }else{
        uMotor.turnRight(90-angle);
    }
    delay(15);
    exit(0);
}

int checkDifferences(){
    for (int i = 90; i <= 180; i = i + ROTATE_INTERVAL) {
        head.rotate(i);
        int distance = head.checkDistance();
        if (distance - DISTANCE_THRESHOLD > DIFFERENCE_THRESHOLD) {
            return i;
        }
    }

    for (int i = 90; i >= 0; i = i - ROTATE_INTERVAL) {
        head.rotate(i);
        int distance = head.checkDistance();
        if (distance - DISTANCE_THRESHOLD > DIFFERENCE_THRESHOLD) {
            return i;
        }
    }

    return -1;
}