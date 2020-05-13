#include "length_expression.h"

LengthExpression::LengthExpression(Expression *expression, const yy::location &location)
    : Expression(location), expression(expression) {

}

LengthExpression::~LengthExpression() {
  delete expression;
}

void LengthExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
