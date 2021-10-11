// Defining motor pins
int motor1pin1 = 6;
int motor1pin2 = 10;

int motor2pin1 = 9;
int motor2pin2 = 11;

// Signal
#define echoPin 2
#define trigPin 3

long duration;
int distance;

// Rotating head
#include <Servo.h>
Servo servo;

void setup() {
    // Motor pins
    pinMode(motor1pin1, OUTPUT);
    pinMode(motor1pin2, OUTPUT);
    pinMode(motor2pin1, OUTPUT);
    pinMode(motor2pin2, OUTPUT);

    // Ultrasound pins
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);

    // Servo pins
    servo.attach(12);

    // Serial monitor
    Serial.begin(9600);
    Serial.println("Driving towards a wall and NOT hitting it!");
}

void moveForward() {
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
}

void stop() {
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
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
    servo.write(90);
    delay(100);
    checkDistance();
    double init_distance = distance;
    moveForward();
    while(distance > 30){
        checkDistance();
        delay(15);
    }
    stop();
    Serial.print("Done lol");
    delay(15);
    exit(0);
}