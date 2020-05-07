#pragma once

#include "type.h"

class Int : public Type {
 public:
  explicit Int(int value);

  ~Int() override = default;

  int toInt() const override;
  bool toBoolean() const override;

 private:
  int value_;
};


