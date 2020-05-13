#pragma once

#include "basic_type.h"

class Int : public BasicType {
 public:
  explicit Int(int value = 0);

  Int(const Int& other) = default;
  Int& operator=(const Int& other) = default;

  ~Int() override = default;

  int toInt() const override;
  bool toBool() const override;

  Type getType() const override;

 private:
  int value_;
};


