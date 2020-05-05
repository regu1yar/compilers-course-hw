#include "int_value_expression.h"


IntValueExpression::IntValueExpression(int value, const yy::location &location)
    : value(value)
    , location(location) {

}
