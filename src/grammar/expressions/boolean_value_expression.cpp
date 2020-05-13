#include "boolean_value_expression.h"

BooleanValueExpression::BooleanValueExpression(bool value, const yy::location &location)
    : Expression(location), value(value) {

}

BooleanValueExpression::~BooleanValueExpression() = default;

void BooleanValueExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
