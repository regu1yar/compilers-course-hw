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
  bool toBool() const override;

  Type getType() const override;

  T getElementValue(size_t index) const;
  void setElementValue(size_t index, T value);

  size_t getLength() const;

 private:
  std::vector<T> array_;
};

#include "array_inl.h"
