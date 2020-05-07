#include "less_expression.h"

LessExpression::LessExpression(
    Expression *first_operand,
    Expression *second_operand,
    const yy::location &location
) : first_operand(first_operand),
    second_operand(second_operand),
    location(location) {

}

LessExpression::~LessExpression() {
  delete first_operand;
  delete second_operand;
}

void LessExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
