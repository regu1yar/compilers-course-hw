#pragma once

#include "type.h"

class Boolean : public Type {
 public:
  explicit Boolean(bool value);

  ~Boolean() override = default;

  int toInt() const override;
  bool toBoolean() const override;

 private:
  bool value_;
};


