#include "and_expression.h"

AndExpression::AndExpression(
    Expression *first_operand,
    Expression *second_operand,
    const yy::location &location
    ) : Expression(location),
        first_operand(first_operand),
        second_operand(second_operand) {

}

AndExpression::~AndExpression() {
  delete first_operand;
  delete second_operand;
}

void AndExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
