#include <Arduino.h>
#include <ir/receiver.hpp>

#define IN_SIGNAL_PIN 12
const unsigned int listener_array_size = 90 * 8;

ir::Receiver receiver(IN_SIGNAL_PIN);
boolean listener_data[listener_array_size];

void setup() {
  Serial.begin(9600);

  pinMode(IN_SIGNAL_PIN, INPUT);
}

void loop() {
  // Receive for 2 seconds and print results
  receiver.receive(2000, listener_data, listener_array_size);

  for (unsigned int i = 0; i < listener_array_size; i++) {
    Serial.print(listener_data[i] ? "1" : "0");
  }

  Serial.println("");
  
  delay(500);
}
