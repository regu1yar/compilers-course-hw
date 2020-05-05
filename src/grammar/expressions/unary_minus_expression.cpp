#include "unary_minus_expression.h"

UnaryMinusExpression::UnaryMinusExpression(Expression *operand, const yy::location &location)
    : operand(operand)
    , location(location) {

}
