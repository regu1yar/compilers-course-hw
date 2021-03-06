#include "array_element_expression.h"

#include <utility>

ArrayElementExpression::ArrayElementExpression(
    std::string identifier,
    Expression *index_expression,
    const yy::location &location
    ) : Expression(location),
        identifier(std::move(identifier)),
        index_expression(index_expression) {

}

ArrayElementExpression::~ArrayElementExpression() {
  delete index_expression;
}

void ArrayElementExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
