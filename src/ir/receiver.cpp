#include <ir/receiver.hpp>

namespace ir {
Receiver::Receiver(int receiver_pin) : receiver_pin_(receiver_pin) {

}

void Receiver::receive(int timeout_ms) {

}

bool* Receiver::get_recording() {
    return nullptr;
}
}
