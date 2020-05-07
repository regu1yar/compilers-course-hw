#include "equals_expression.h"

EqualsExpression::EqualsExpression(
    Expression *first_operand,
    Expression *second_operand,
    const yy::location &location
) : first_operand(first_operand),
    second_operand(second_operand),
    location(location) {

}

EqualsExpression::~EqualsExpression() {
  delete first_operand;
  delete second_operand;
}

void EqualsExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
