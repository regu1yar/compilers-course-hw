#include "negation_expression.h"

NegationExpression::NegationExpression(Expression *operand, const yy::location &location)
    : Expression(location), operand(operand){

}

NegationExpression::~NegationExpression() {
  delete operand;
}

void NegationExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
