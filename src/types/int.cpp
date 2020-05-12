#include "int.h"

#include "exceptions.h"

Int::Int(int value) : value_(value) {

}

int Int::toInt() const {
  return value_;
}

bool Int::toBool() const {
  throw TypeMismatchException("Expected type: boolean, but int were provided");
}

Type Int::getType() const {
  return Type::INT;
}
