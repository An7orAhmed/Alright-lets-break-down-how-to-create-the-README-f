#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>

#define red    5
#define green  6
#define yellow 7
#define sPin   8
#define motorA 9
#define motorB 10
#define buzzer A1

OneWire oneWire(2);
DallasTemperature temp(&oneWire);
SoftwareSerial bt(11, 12);

byte motor = 0;
float tmp, turbi, phVal;
long pMs;

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  temp.begin();

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sPin, OUTPUT);

  center();
}

void loop() {
  temp.requestTemperatures();
  float tempC = temp.getTempCByIndex(0);
  if (tempC != DEVICE_DISCONNECTED_C) tmp = tempC;
  phVal = analogRead(A4);
  turbi = analogRead(A5);
  phVal = map(phVal, 0, 4096, 0, 140);
  turbi = map(turbi, 0, 4096, 1, 1000);
  phVal /= 10;

  checkCommand(bt);
  checkCommand(Serial);

  if (motor == 0) {
    digitalWrite(red, 1);
    digitalWrite(motorA, 0);
    digitalWrite(motorB, 0);
  }
  else if (motor == 1) {
    digitalWrite(red, 0);
    digitalWrite(motorA, 1);
    delay(8);
    digitalWrite(motorA, 0);
    delay(12);
    digitalWrite(motorB, 0);
  }
  else if (motor == 2) {
    digitalWrite(red, 0);
    digitalWrite(motorA, 0);
    digitalWrite(motorB, 1);
    delay(8);
    digitalWrite(motorB, 0);
    delay(12);
  }

  if (millis() - pMs > 1000) {
    logger(bt);
    logger(Serial);
    pMs = millis();
  }
}

void checkCommand(Stream &serial) {
  if (serial.available()) {
    char cmd = serial.read();
    while (serial.available()) serial.read();
    beep(200);

    if (cmd == 's') motor = 0;
    else if (cmd == 'b') motor = 1;
    else if (cmd == 'f') motor = 2;

    else if (cmd == 'l') leftTurn();
    else if (cmd == 'c') center();
    else if (cmd == 'r') rightTurn();
  }
}

void logger(Stream &serial) {
  serial.println((String)"Temp: " + tmp + " dC");
  serial.println((String)"Turbidity: " + turbi + " NTU");
  serial.println((String)"pH Value: " + phVal);
  serial.println("--------------");
}

void beep(int d) {
  digitalWrite(buzzer, 1);
  delay(d);
  digitalWrite(buzzer, 0);
}

void center() {
  digitalWrite(yellow, 1);
  for (byte i = 0; i < 50; i++) {
    digitalWrite(sPin, 1);
    delayMicroseconds(1500);
    digitalWrite(sPin, 0);
    delayMicroseconds(18500);
  }
}

void rightTurn() { // 0 Degree
  digitalWrite(yellow, 0);
  for (byte i = 0; i < 50; i++) {
    digitalWrite(sPin, 1);
    delayMicroseconds(800);
    digitalWrite(sPin, 0);
    delayMicroseconds(19200);
  }
}

void leftTurn() { // 180 Degree
  digitalWrite(yellow, 0);
  for (byte i = 0; i < 50; i++) {
    digitalWrite(sPin, 1);
    delayMicroseconds(2200);
    digitalWrite(sPin, 0);
    delayMicroseconds(17800);
  }
}
