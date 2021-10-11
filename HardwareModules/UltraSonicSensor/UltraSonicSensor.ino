/*
* Wire Vcc to 5V
* Wire Trig to D3
* Wire Echo to D2
* Wire GND to GND
*/

#define echoPin 2
#define trigPin 3

long duration;
int distance;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    Serial.println("Sensor test");
}

void loop() {
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