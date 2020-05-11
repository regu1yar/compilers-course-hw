#pragma once

#include <exception>
#include <string>
#include <utility>


class UndeclaredVariableException : public std::exception {
 public:
  explicit UndeclaredVariableException(std::string message)
      : message_(std::move(message))
  { }

  const char* what() const noexcept override {
    return message_.c_str();
  }

 private:
  std::string message_;
};


class TypeMismatchException : public std::exception {
 public:
  explicit TypeMismatchException(std::string message)
      : message_(std::move(message))
  { }

  const char* what() const noexcept override {
    return message_.c_str();
  }

 private:
  std::string message_;
};


class DoubleDeclarationException : public std::exception {
 public:
  explicit DoubleDeclarationException(std::string message)
      : message_(std::move(message))
  { }

  const char* what() const noexcept override {
    return message_.c_str();
  }

 private:
  std::string message_;
};


class OutOfRangeException : public std::exception {
 public:
  explicit OutOfRangeException(std::string message)
      : message_(std::move(message))
  { }

  const char* what() const noexcept override {
    return message_.c_str();
  }

 private:
  std::string message_;
};

class UninitializedVariableException : public std::exception {
 public:
  explicit UninitializedVariableException(std::string message)
      : message_(std::move(message))
  { }

  const char* what() const noexcept override {
    return message_.c_str();
  }

 private:
  std::string message_;
};
