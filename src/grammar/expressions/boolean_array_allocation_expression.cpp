#include "boolean_array_allocation_expression.h"

BooleanArrayAllocationExpression::BooleanArrayAllocationExpression(Expression *expression, const yy::location &location)
    : array_size(expression)
    , location(location) {

}