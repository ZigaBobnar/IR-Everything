#ifndef IR_RECEIVER_HPP_
#define IR_RECEIVER_HPP_

#include <Arduino.h>

namespace ir {
class Receiver {
private:
  int receiver_pin_;
  String recording_;

public:
  Receiver(int receiver_pin);

  void receive(int duration_ms);
  String get_recording();
  void clear();
};
}

#endif  // IR_RECEIVER_HPP_
