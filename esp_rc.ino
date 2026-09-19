// ZAN Tech Bluetooth RC Car - ESP32 with Built-in Bluetooth
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Enable it in Tools > Board menu or partition scheme.
#endif

BluetoothSerial SerialBT;

#define ENA 25
#define IN1 26
#define IN2 27
#define IN3 14
#define IN4 12
#define ENB 13

char command;
int speed_left = 200;
int speed_right = 200;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ZAN_Tech_Car");  // Bluetooth device name shown when pairing

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.println("Car ready. Pair with 'ZAN_Tech_Car' via Bluetooth.");
  Serial.println("Send: F B L R I G H J S | speed 1-9,q");
}

void loop() {
  if (SerialBT.available() > 0) {
    command = SerialBT.read();
    handleCommand(command);
  }

  // Optional: also allow testing via USB Serial Monitor
  if (Serial.available() > 0) {
    command = Serial.read();
    handleCommand(command);
  }
}

void handleCommand(char command) {
  switch (command) {
    case 'F': forward();       break;
    case 'B': backward();      break;
    case 'L': right();         break;
    case 'R': left();          break;
    case 'G': forward_left();  break;
    case 'I': forward_right(); break;
    case 'H': back_left();     break;
    case 'J': back_right();    break;
    case 'S': stopy();         break;

    case '1': speed_left = 20;  speed_right = 20;  break;
    case '2': speed_left = 40;  speed_right = 40;  break;
    case '3': speed_left = 60;  speed_right = 60;  break;
    case '4': speed_left = 80;  speed_right = 80;  break;
    case '5': speed_left = 100; speed_right = 100; break;
    case '6': speed_left = 120; speed_right = 120; break;
    case '7': speed_left = 140; speed_right = 140; break;
    case '8': speed_left = 160; speed_right = 160; break;
    case '9': speed_left = 200; speed_right = 200; break;
    case 'q': speed_left = 255; speed_right = 255; break;
  }
}

// ===== MOVEMENT FUNCTIONS =====

void forward() {
  analogWrite(ENA, speed_left);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, speed_right);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  analogWrite(ENA, speed_left);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, speed_right);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  analogWrite(ENA, speed_left);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, speed_right);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  analogWrite(ENA, speed_left);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, speed_right);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void forward_left() {
  analogWrite(ENA, speed_left / 2);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, speed_right);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void forward_right() {
  analogWrite(ENA, speed_left);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, speed_right / 2);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void back_left() {
  analogWrite(ENA, speed_left / 2);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, speed_right);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void back_right() {
  analogWrite(ENA, speed_left);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, speed_right / 2);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopy() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
