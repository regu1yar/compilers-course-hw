#pragma once

#include <string>

class Error {
 public:
  virtual std::string toString() const = 0;
};


