#include <Arduino.h>
#include <ir/receiver.hpp>

#define IN_SIGNAL_PIN 12
#define LISTENER_ARRAY_SIZE 720

ir::Receiver receiver(IN_SIGNAL_PIN);
boolean listener_data[720];

void setup() {
  Serial.begin(9600);

  pinMode(IN_SIGNAL_PIN, INPUT);
}

void loop() {
  // Receive for 1 second and print results
  receiver.receive(2000, listener_data, LISTENER_ARRAY_SIZE);

  for (unsigned int i = 0; i < LISTENER_ARRAY_SIZE; i++) {
    Serial.print(listener_data[i] ? "1" : "0");
  }

  Serial.println("");
  
  delay(500);
}
