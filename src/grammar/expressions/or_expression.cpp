#include "or_expression.h"

OrExpression::OrExpression(
    Expression *first_operand,
    Expression *second_operand,
    const yy::location &location
) : first_operand(first_operand),
    second_operand(second_operand),
    location(location) {

}

OrExpression::~OrExpression() {
  delete first_operand;
  delete second_operand;
}

void OrExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
