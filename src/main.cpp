#include <Arduino.h>

#define IN_SIGNAL_PIN 0

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  Serial.println(analogRead(IN_SIGNAL_PIN));
  delay(2);
}
