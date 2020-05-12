#include "percent_expression.h"

PercentExpression::PercentExpression(
    Expression *first_operand,
    Expression *second_operand,
    const yy::location &location
    ) : Expression(location),
        first_operand(first_operand),
        second_operand(second_operand) {

}

PercentExpression::~PercentExpression() {
  delete first_operand;
  delete second_operand;
}

void PercentExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
