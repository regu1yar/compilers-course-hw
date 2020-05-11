#include "int.h"

#include "exceptions.h"

Int::Int(int value) : value_(value) {

}

int Int::toInt() const {
  return value_;
}

bool Int::toBoolean() const {
  throw TypeMismatchException("Expected type: boolean, but int were provided");
}

std::string Int::getName() const {
  return "int";
}
