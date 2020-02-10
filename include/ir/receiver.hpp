#ifndef IR_RECEIVER_HPP_
#define IR_RECEIVER_HPP_

#include <Arduino.h>

namespace ir {
class Receiver {
private:
  int receiver_pin_;

public:
  Receiver(int receiver_pin);

  void receive(
    unsigned long duration_ms,
    boolean* output,
    unsigned int max_len);
};
}

#endif  // IR_RECEIVER_HPP_
