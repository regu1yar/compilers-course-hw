#include "boolean.h"

#include "exceptions.h"

Boolean::Boolean(bool value) : value_(value) {

}

int Boolean::toInt() const {
  throw TypeMismatchException("Expected type: int, but boolean were provided");
}

bool Boolean::toBool() const {
  return value_;
}

Type Boolean::getType() const {
  return Type::BOOLEAN;
}