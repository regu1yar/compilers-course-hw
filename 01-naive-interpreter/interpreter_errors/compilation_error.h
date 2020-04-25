#pragma once

#include <sstream>

#include "error.h"

class CompilationError : public Error {
 public:
  CompilationError(size_t line, size_t column, std::string message)
  : line_(line)
  , column_(column)
  , message_(std::move(message))
  { }

  CompilationError(const CompilationError&) = default;
  CompilationError& operator=(const CompilationError&) = default;

  std::string toString() const override {
    std::ostringstream oss;
    oss << "Compilation error: "
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


