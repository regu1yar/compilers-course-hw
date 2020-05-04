#include "int_value_expression.h"

#include "compilation_error.h"

IntValueExpression::IntValueExpression(int value, const yy::location &location)
    : value_(value)
    , location_(location) {

}

IntValueExpression::~IntValueExpression() {

}

ExpressionType IntValueExpression::getType() {
  return INT;
}

int IntValueExpression::evaluateInt() const {
  return value_;
}

bool IntValueExpression::evaluateBoolean() const {
  throw CompilationError(
      location_.begin.line,
      location_.begin.column,
      "Expected boolean value, int value provided"
  );
}
