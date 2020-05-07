#include "star_expression.h"

StarExpression::StarExpression(
    Expression *first_operand,
    Expression *second_operand,
    const yy::location &location
) : first_operand(first_operand),
    second_operand(second_operand),
    location(location) {

}

StarExpression::~StarExpression() {
  delete first_operand;
  delete second_operand;
}

void StarExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
