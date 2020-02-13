#include <ir/receiver.hpp>

namespace ir {
Receiver::Receiver(int receiver_pin) : receiver_pin_(receiver_pin) {

}

IRData Receiver::receive(unsigned int require_exact_recordings) {
  return IRData();
}
}
