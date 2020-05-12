#include "or_expression.h"

OrExpression::OrExpression(
    Expression *first_operand,
    Expression *second_operand,
    const yy::location &location
    ) : Expression(location),
        first_operand(first_operand),
        second_operand(second_operand) {

}

OrExpression::~OrExpression() {
  delete first_operand;
  delete second_operand;
}

void OrExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
