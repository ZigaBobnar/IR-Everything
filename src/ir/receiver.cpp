#include <ir/receiver.hpp>

namespace ir {
Receiver::Receiver(int receiver_pin) : receiver_pin_(receiver_pin) {

}

void Receiver::receive(unsigned long duration_ms, boolean* output, unsigned int max_len) {
  unsigned long start_time = millis();
  unsigned int position = 0;

  while(millis() - start_time <= duration_ms) {
    if (position > max_len)
      break;

    output[position++] = digitalRead(receiver_pin_) == 1;

    delay(1);
  }
}
}
