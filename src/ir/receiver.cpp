#include <ir/receiver.hpp>

namespace ir {
Receiver::Receiver(int receiver_pin) : receiver_pin_(receiver_pin) {

}

void Receiver::receive(int duration_ms) {
  unsigned long start_time = millis();

  while(millis() - start_time < duration_ms) {
    recording_ += ((digitalRead(receiver_pin_) == 1) ? "1" : "0");
    delay(2);
  }
}

String Receiver::get_recording() {
  return recording_;
}

void Receiver::clear() {
  recording_ = "";
}
}
