#include <Arduino.h>
#include <IRremote.h>

const int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void dump_results(decode_results *results);

void setup() {
  Serial.begin(9600);

  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    dump_results(&results);
    irrecv.resume();
  }
}

void dump_results(decode_results *results) {
  int count = results->rawlen;

  switch(results->decode_type) {
    case UNKNOWN:
      Serial.print("Unknown encoding: ");
      break;
    case NEC:
      Serial.print("Decoded NEC:");
      break;
    case SONY:
      Serial.print("Decoded SONY:");
      break;
    case RC5:
      Serial.print("Decoded RC5:");
      break;
    case RC6:
      Serial.print("Decoded RC6:");
      break;
    case PANASONIC:
      Serial.print("Decoded PANASONIC - Address:");
      Serial.print(results->address, HEX);
      Serial.print(" Value: ");
      break;
    case LG:
      Serial.print("Decoded LG:");
      break;
    case JVC:
      Serial.print("Decoded JVC:");
      break;
    case AIWA_RC_T501:
      Serial.print("Decoded AIWA RC T501:");
      break;
    case WHYNTER:
      Serial.print("Decoded WHYTNER:");
      break;
    default:
      Serial.print("Decoded (Unexpected encoding ");
      Serial.print(results->decode_type);
      Serial.print("):");
      break;
  }

  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("RAW (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 1; i < count; ++i) {
    if (i & 1) {
      Serial.print(results->rawbuf[i] * USECPERTICK, DEC);
    } else {
      Serial.write('-');
      Serial.print((unsigned long)results->rawbuf[i] * USECPERTICK, DEC);
    }

    Serial.print(" ");
  }

  Serial.println();
}
