#pragma once

#include "basic_type.h"

class Boolean : public BasicType {
 public:
  explicit Boolean(bool value = false);

  ~Boolean() override = default;

  int toInt() const override;
  bool toBoolean() const override;

  std::string getName() const override;

 private:
  bool value_;
};


