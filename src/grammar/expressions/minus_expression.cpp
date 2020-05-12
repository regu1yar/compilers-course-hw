#include "minus_expression.h"

MinusExpression::MinusExpression(
    Expression *first_operand,
    Expression *second_operand,
    const yy::location &location
    ) : Expression(location),
        first_operand(first_operand),
        second_operand(second_operand) {

}

MinusExpression::~MinusExpression() {
  delete first_operand;
  delete second_operand;
}

void MinusExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
