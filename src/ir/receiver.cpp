#include <ir/receiver.hpp>
#include <IRRemote.h>

namespace ir {
Receiver::Receiver(int receiver_pin) : receiver_pin_(receiver_pin) {

}

IRData Receiver::receive(unsigned int require_exact_recordings) {
  IRrecv irrecv(this->receiver_pin_);
  irrecv.enableIRIn();

  unsigned int received_count = 0;
  decode_results ir_receive_result, ir_receive_current_result;
  bool results_valid = true;

  while(true) {
    if (irrecv.decode(&ir_receive_current_result)) {
      if (received_count == 0) {
        ir_receive_result = ir_receive_current_result;
      }

      if (ir_receive_current_result.rawlen != ir_receive_result.rawlen ||
        ir_receive_current_result.decode_type != ir_receive_result.decode_type ||
        ir_receive_current_result.value != ir_receive_result.value) {
        results_valid = false;
        break;
      }

      received_count++;
      if (received_count >= require_exact_recordings) {
        break;
      }

      irrecv.resume();
    }
  }

  if (results_valid) {
    IRData result;
    // TODO
    Serial.print("Received: ");
    Serial.println(ir_receive_result.value);

    return result;
  }

  return IRData(false);
}
}
