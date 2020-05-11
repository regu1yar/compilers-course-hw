#pragma once

#include <string>

class BasicType {
 public:
  virtual ~BasicType() = 0;

  virtual int toInt() const = 0;
  virtual bool toBoolean() const = 0;

  virtual std::string getName() const = 0;
};
