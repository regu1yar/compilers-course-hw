#include "int_array_allocation_expression.h"

IntArrayAllocationExpression::IntArrayAllocationExpression(Expression *expression, const yy::location &location)
    : Expression(location), array_size(expression) {

}

IntArrayAllocationExpression::~IntArrayAllocationExpression() {
  delete array_size;
}

void IntArrayAllocationExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
