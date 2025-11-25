#include <SoftwareSerial.h>

// Bluetooth Serial
SoftwareSerial BT(2, 3); // RX, TX

// Motor control pins
int ENA = 5;   // PWM for Left Motor
int IN1 = 8;
int IN2 = 9;

int ENB = 6;   // PWM for Right Motor
int IN3 = 10;
int IN4 = 11;

char c1;   // First character (F or B)
char c2;   // Second character (1,2,3)

int speedValue = 180; // Default speed

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopCar();

  Serial.println("PWM RC Car Ready! Commands: F1 F2 F3 B1 B2 B3 L R S");
}

void loop() {

  // Bluetooth data read
  if (BT.available() >= 2) {
    c1 = BT.read();
    c2 = BT.read();
    processCommand(c1, c2);
  }

  // Serial Monitor data read
  if (Serial.available() >= 2) {
    c1 = Serial.read();
    c2 = Serial.read();
    processCommand(c1, c2);
  }
}

void processCommand(char m, char s) {
  // Speed decode
  if (s == '1') speedValue = 120;
  else if (s == '2') speedValue = 180;
  else if (s == '3') speedValue = 255;

  if (m == 'F') forward();
  else if (m == 'B') backward();
  else if (m == 'L') left();
  else if (m == 'R') right();
  else if (m == 'S') stopCar();

  Serial.print("Command: ");
  Serial.print(m);
  Serial.print(s);
  Serial.print(" | Speed: ");
  Serial.println(speedValue);
}

// ---------- MOVEMENTS ----------

void forward() {
  analogWrite(ENA, speedValue);
  analogWrite(ENB, speedValue);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  analogWrite(ENA, speedValue);
  analogWrite(ENB, speedValue);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
