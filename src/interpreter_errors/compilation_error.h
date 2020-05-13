#pragma once

#include <sstream>

#include "error.h"

class CompilationError : public Error {
 public:
  CompilationError(std::string message, size_t line, size_t column)
  : message_(std::move(message))
  , line_(line)
  , column_(column) {

  }

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
  std::string message_;
  size_t line_;
  size_t column_;
};


