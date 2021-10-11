#include <Servo.h>

#define echoPin 2
#define trigPin 3

long duration;
int distance;

Servo servo;
int counter = 0;

void setup() {
    servo.attach(12);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    Serial.println("Sensor test");
}

void checkDistance() {
    // Clears condition
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Sets trig pin high
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Reads the echoPin
    duration = pulseIn(echoPin, HIGH);
    // Calculates distance
    distance = duration * 0.034 / 2; // Speed of sound

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
}

void loop() {
    while (counter < 2) {
        for (int i=0; i<180; i++) {
            servo.write(i);
            checkDistance();
            delay(15);
        }
        for (int i = 180; i > 0; i--) {
            servo.write(i);
            checkDistance();
            delay(15);
        }
        counter++;
    }
    exit(0);
}