#ifndef IR_IRDATA_HPP_
#define IR_IRDATA_HPP_

namespace ir {
class IRData {
private:
  bool data_valid_;
public:
  IRData();
  IRData(bool data_valid);
};
}

#endif  // IR_IRDATA_HPP_
