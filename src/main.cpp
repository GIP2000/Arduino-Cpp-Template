#include "../lib/cores/arduino/Arduino.h"

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(13, HIGH);
  Serial.println("HIGH");
  delay(5000);
  digitalWrite(13, LOW);
  Serial.println("LOW");
  delay(5000);
}
