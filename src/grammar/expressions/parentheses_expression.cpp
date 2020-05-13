#include "parentheses_expression.h"

ParenthesesExpression::ParenthesesExpression(Expression *expression, const yy::location& location)
    : Expression(location), expression(expression) {

}

ParenthesesExpression::~ParenthesesExpression() {
  delete expression;
}

void ParenthesesExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
