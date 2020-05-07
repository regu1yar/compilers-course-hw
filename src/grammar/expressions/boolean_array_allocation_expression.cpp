#include "boolean_array_allocation_expression.h"

BooleanArrayAllocationExpression::BooleanArrayAllocationExpression(Expression *expression, const yy::location &location)
    : array_size(expression)
    , location(location) {

}

BooleanArrayAllocationExpression::~BooleanArrayAllocationExpression() {
  delete array_size;
}

void BooleanArrayAllocationExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
