#include "length_expression.h"

LengthExpression::LengthExpression(Expression *expression, const yy::location &location)
    : expression(expression)
    , location(location) {

}
