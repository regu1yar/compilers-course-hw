#pragma once

#include <string>
#include <sstream>
#include <utility>

#include <sstream>

#include "error.h"

class RuntimeError : public Error {
 public:
  RuntimeError(size_t line, size_t column, std::string message)
    : line_(line)
    , column_(column)
    , message_(std::move(message))
  { }

  RuntimeError(const RuntimeError&) = default;
  RuntimeError& operator=(const RuntimeError&) = default;

  std::string toString() const override {
    std::ostringstream oss;
    oss << "Runtime error: "
        << message_
        << " at line: " << line_
        << ", column: " << column_;
    return oss.str();
  }

 private:
  size_t line_;
  size_t column_;
  std::string message_;
};


