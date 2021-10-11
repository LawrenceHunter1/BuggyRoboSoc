int motor1pin1 = 6;
int motor1pin2 = 10;

int motor2pin1 = 9;
int motor2pin2 = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}

void moveForward() {
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
}

void moveBackward() {
    digitalWrite(motor1pin1, LOW);      
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
}

void stop() {
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:   
  moveForward();
  delay(500);

  moveBackward();
  delay(500);

  stop();
  exit(0);
}