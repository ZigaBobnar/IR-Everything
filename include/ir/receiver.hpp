#ifndef IR_RECEIVER_HPP_
#define IR_RECEIVER_HPP_

#include <ir/irdata.hpp>

namespace ir {
class Receiver {
private:
  int receiver_pin_;

public:
  Receiver(int receiver_pin);

  IRData receive(unsigned int require_exact_recordings = 1);
};
}

#endif  // IR_RECEIVER_HPP_
