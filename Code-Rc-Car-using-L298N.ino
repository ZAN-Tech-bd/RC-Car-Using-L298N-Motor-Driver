#include <SoftwareSerial.h>

// Bluetooth on SoftwareSerial pins
SoftwareSerial BT(2, 3);   // RX, TX

// Motor pins
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

char cmd;

void setup() {
  Serial.begin(9600);   // For Serial Monitor
  BT.begin(9600);       // For HC-05

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopCar();
  Serial.println("RC Car Ready! Send F, B, L, R, S");
}

void loop() {

  // Bluetooth commands
  if (BT.available()) {
    cmd = BT.read();
    controlCar(cmd);
  }

  // Serial monitor commands
  if (Serial.available()) {
    cmd = Serial.read();
    controlCar(cmd);
  }
}

// MAIN CAR CONTROL
void controlCar(char c) {
  if (c == 'F') forward();
  else if (c == 'B') backward();
  else if (c == 'L') left();
  else if (c == 'R') right();
  else if (c == 'S') stopCar();

  Serial.print("Command: ");
  Serial.println(c);
}

// ------- CAR MOVEMENTS --------

void forward() {
  // Both motors forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  // Both motors backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  // Left motor backward, right motor forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  // Left motor forward, right motor backward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  // Stop all motors
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
