#include <ir/receiver.hpp>

namespace ir {
Receiver::Receiver(int receiver_pin) : receiver_pin_(receiver_pin) {

}

// The digital signal is ACTIVE LOW
// output will be filled with parsed bytes for NEC protocol (~562.5us)
// -> 562.5 high, 562.5 low for logic 1
// -> 562.5 high, 3x 562.5 low (1687.5) for logic 0
// I guess it would be best if listening only for changes and decode the signal by calculating time between them
// Maybe even just listen for the time digitalRead returns low and decode that interval ==> just 
void Receiver::receive(unsigned long duration_ms, boolean* output, unsigned int max_len) {
  unsigned long start_time = millis();
  unsigned int position = 0;
  
  while(digitalRead(receiver_pin_) == 0) {
    // Wait for the end of current state as we are in the middle of transmission
    delayMicroseconds(4);
  }

  boolean current_readout = digitalRead(receiver_pin_);

  unsigned long current_us = micros();
  boolean reading = true;
  while(true) {
    boolean new_readout = digitalRead(receiver_pin_);

    if (new_readout != current_readout) {
      reading = true;
      /*if (current_readout == 0) {
        unsigned long time_diff = micros() - current_us;

        boolean decoded = 1;
        if (time_diff < 1125) {
          decoded = 0;
        }

        //Serial.print(decoded ? "1" : "0");
        //output[position++] = decoded;
      }*/

      char buffer[200];
      sprintf(buffer, "Received: %d, Time: %dus", (int)current_readout, (int)(micros() - current_us));
      Serial.println(buffer);

      current_us = micros();
      current_readout = new_readout;
    } else {
      if (reading && micros() - current_us > 10000) {
        Serial.println("-----------------------------");
        current_us = micros();
        reading = false;
      }
    }

    //if (millis() - start_time <= duration_ms || position >= max_len) {
    //   return;
    //}
    delayMicroseconds(20);
  }
}
}
