#include <Servo.h>

/*
* Wire brown to GND
* Wire red to 5V
* Wire orange to 12
*/

Servo servo;
int counter = 0;

void setup() {
    servo.attach(12);
    Serial.begin(9600);
}

void loop() {
    while (counter < 2) {
        for (int i=0; i<180; i++) {
            servo.write(i);
            Serial.print(i);
            Serial.println(" degrees");
            delay(15);
        }
        for (int i = 180; i > 0; i--) {
            servo.write(i);
            Serial.print(i);
            Serial.println(" degrees");
            delay(15);
        }
        counter++;
    }
    exit(0);
}