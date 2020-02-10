#include <Arduino.h>
#include <ir/receiver.hpp>

#define IN_SIGNAL_PIN 12

ir::Receiver receiver(IN_SIGNAL_PIN);

void setup() {
  Serial.begin(9600);

  pinMode(IN_SIGNAL_PIN, INPUT);
}

void loop() {
  // Receive for 1 second and print results
  receiver.receive(2000); 
  String recording = receiver.get_recording();
  receiver.clear();

  delay(500);
}
