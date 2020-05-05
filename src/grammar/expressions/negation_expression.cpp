#include "negation_expression.h"

NegationExpression::NegationExpression(Expression *operand, const yy::location &location)
    : operand(operand)
    , location(location) {

}
