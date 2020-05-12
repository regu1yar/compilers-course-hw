#include "basic_type.h"

#include <string>

BasicType::~BasicType() = default;

std::string toString(Type type) {
  switch (type) {
    case Type::INT:
      return "int";
    case Type::BOOLEAN:
      return "boolean";
    case Type::INT_ARRAY:
      return "int[]";
    case Type::BOOLEAN_ARRAY:
      return "boolean[]";
  }
}
