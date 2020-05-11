#pragma once

#include <string>
#include <vector>

#include "basic_type.h"

template<typename T>
class Array : public BasicType {
 public:
  explicit Array(size_t size = 0);

  ~Array() override = default;

  int toInt() const override;
  bool toBoolean() const override;

  std::string getName() const override;

 private:
  std::vector<T> array_;
};

#include "array_inl.h"
