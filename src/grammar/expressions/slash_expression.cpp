#include "slash_expression.h"

SlashExpression::SlashExpression(
    Expression *first_operand,
    Expression *second_operand,
    const yy::location &location
    ) : Expression(location),
        first_operand(first_operand),
        second_operand(second_operand) {

}

SlashExpression::~SlashExpression() {
  delete first_operand;
  delete second_operand;
}

void SlashExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
