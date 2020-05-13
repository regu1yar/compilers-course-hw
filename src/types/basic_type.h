#pragma once

#include <string>

enum class Type {
  INT,
  BOOLEAN,
  INT_ARRAY,
  BOOLEAN_ARRAY
};

std::string toString(Type type);

class BasicType {
 public:
  virtual ~BasicType() = 0;

  virtual int toInt() const = 0;
  virtual bool toBool() const = 0;

  virtual Type getType() const = 0;
};
