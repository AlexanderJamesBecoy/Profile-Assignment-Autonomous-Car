
#include <AFMotor.h>
#define echoPin 10
#define trigPin 13
long duration, distance;

AF_DCMotor motorRA(1, MOTOR12_1KHZ);
AF_DCMotor motorRV(2, MOTOR12_1KHZ);
AF_DCMotor motorLV(3, MOTOR34_1KHZ);
AF_DCMotor motorLA(4, MOTOR34_1KHZ);

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin,  OUTPUT);

  delay(5000);
  motorRA.setSpeed(50);
  motorRV.setSpeed(50);
  motorLV.setSpeed(50);
  motorLA.setSpeed(50);
  motorVooruit();
}

void loop() { 
  meetAfstand();
  if (distance <= 15 && distance > 5) {
    motorStop();
    draaiLinks();
    meetAfstand();
    if (distance <= 15 && distance > 5) {
      draaiRechts();
      draaiRechts();
      meetAfstand();
      if (distance <= 15 && distance > 5) {
        draaiLinks();
        motorAchteruit();
      }
    }
  }else if (distance <= 5) {
    motorAchteruit();
    motorStop();
    draaiLinks();
    meetAfstand();
    if (distance <= 15 && distance > 5) {
      draaiRechts();
      draaiRechts();
      meetAfstand();
      if (distance <= 15 && distance > 5) {
        draaiLinks();
        motorAchteruit();
      }
    }
  }else{
    motorVooruit();
  }
  delay(500);
}

void meetAfstand() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
}

void motorVooruit() {
  motorRA.setSpeed(150);
  motorRV.setSpeed(150);
  motorLV.setSpeed(150);
  motorLA.setSpeed(150);
  motorRA.run(FORWARD);
  motorRV.run(FORWARD);
  motorLV.run(FORWARD);
  motorLA.run(FORWARD);
}

void motorStop() {
  motorRA.run(RELEASE);
  motorRV.run(RELEASE);
  motorLV.run(RELEASE);
  motorLA.run(RELEASE);
}

void motorAchteruit() {
  for(int i; i < 200; i++) {
    motorRA.setSpeed(i);
    motorRV.setSpeed(i);
    motorLV.setSpeed(i);
    motorLA.setSpeed(i);
    motorRA.run(BACKWARD);
    motorRV.run(BACKWARD);
    motorLV.run(BACKWARD);
    motorLA.run(BACKWARD);
    delay(10);
  }
}

void draaiLinks() {
  for(int i; i <= 180; i++) {
    motorRA.setSpeed(120);
    motorRV.setSpeed(120);
    motorLV.setSpeed(120);
    motorLA.setSpeed(120);
    motorRA.run(FORWARD);
    motorRV.run(FORWARD);
    motorLV.run(BACKWARD);
    motorLA.run(BACKWARD);
    delay(10);
  }
}

void draaiRechts() {
  for(int i; i <= 180; i++) {
    motorRA.setSpeed(120);
    motorRV.setSpeed(120);
    motorLV.setSpeed(120);
    motorLA.setSpeed(120);
    motorRA.run(BACKWARD);
    motorRV.run(BACKWARD);
    motorLV.run(FORWARD);
    motorLA.run(FORWARD);
    delay(10);
  }
}
