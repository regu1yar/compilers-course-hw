#include "boolean.h"

#include "exceptions.h"

Boolean::Boolean(bool value) : value_(value) {

}

int Boolean::toInt() const {
  throw TypeMismatchException("Expected type: int, but boolean were provided");
}

bool Boolean::toBoolean() const {
  return value_;
}

std::string Boolean::getName() const {
  return "boolean";
}