#pragma once

#include <string>

class Error {
 public:
  virtual ~Error() = 0;

  virtual std::string toString() const = 0;
};

inline Error::~Error() = default;
