#include "greater_expression.h"

GreaterExpression::GreaterExpression(
    Expression *first_operand,
    Expression *second_operand,
    const yy::location &location
    ) : Expression(location),
        first_operand(first_operand),
        second_operand(second_operand) {

}

GreaterExpression::~GreaterExpression() {
  delete first_operand;
  delete second_operand;
}

void GreaterExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
