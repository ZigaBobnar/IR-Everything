#ifndef IR_RECEIVER_HPP_
#define IR_RECEIVER_HPP_

namespace ir {
class Receiver {
private:
  int receiver_pin_;

public:
  Receiver(int receiver_pin);

  void receive(int timeout_ms);
  bool* get_recording();
};
}

#endif  // IR_RECEIVER_HPP_
