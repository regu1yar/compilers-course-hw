#include "unary_minus_expression.h"

UnaryMinusExpression::UnaryMinusExpression(Expression *operand, const yy::location &location)
    : operand(operand)
    , location(location) {

}

UnaryMinusExpression::~UnaryMinusExpression() {
  delete operand;
}

void UnaryMinusExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
