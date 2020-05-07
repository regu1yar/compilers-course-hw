#include "parentheses_expression.h"

ParenthesesExpression::ParenthesesExpression(Expression *expression) : expression(expression) {

}

ParenthesesExpression::~ParenthesesExpression() {
  delete expression;
}

void ParenthesesExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
