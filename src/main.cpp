#include <Arduino.h>

#define IN_SIGNAL_PIN 12

int previous_state = 1023;

void setup() {
  Serial.begin(9600);

  pinMode(IN_SIGNAL_PIN, INPUT);
}

void loop() {
  int state = digitalRead(IN_SIGNAL_PIN);
  if (state != previous_state) {
    Serial.println(state);
    previous_state = state;
  }

  delay(2);
}
