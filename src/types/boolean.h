#pragma once

#include "basic_type.h"

class Boolean : public BasicType {
 public:
  explicit Boolean(bool value = false);

  Boolean(const Boolean& other) = default;
  Boolean& operator=(const Boolean& other) = default;

  ~Boolean() override = default;

  int toInt() const override;
  bool toBool() const override;

  Type getType() const override;

 private:
  bool value_;
};


