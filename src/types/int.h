#pragma once

#include "basic_type.h"

class Int : public BasicType {
 public:
  explicit Int(int value = 0);

  ~Int() override = default;

  int toInt() const override;
  bool toBoolean() const override;

  std::string getName() const override;

 private:
  int value_;
};


