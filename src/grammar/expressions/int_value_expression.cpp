#include "int_value_expression.h"


IntValueExpression::IntValueExpression(int value, const yy::location &location)
    : value(value)
    , location(location) {

}

IntValueExpression::~IntValueExpression() {

}

void IntValueExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
