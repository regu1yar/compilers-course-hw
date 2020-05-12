#include "int_value_expression.h"


IntValueExpression::IntValueExpression(int value, const yy::location &location)
    : Expression(location), value(value) {

}

IntValueExpression::~IntValueExpression() = default;

void IntValueExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
