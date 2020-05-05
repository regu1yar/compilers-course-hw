#include "boolean_value_expression.h"

BooleanValueExpression::BooleanValueExpression(bool value, const yy::location &location)
    : value(value)
    , location(location) {

}
