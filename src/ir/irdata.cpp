#include <ir/irdata.hpp>

namespace ir {
IRData::IRData() {
  IRData(true);
}

IRData::IRData(bool data_valid) : data_valid_(data_valid) {

}
}
