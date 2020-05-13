#include "identifier_expression.h"

#include <utility>

IdentifierExpression::IdentifierExpression(std::string identifier, const yy::location &location)
    : Expression(location), identifier(std::move(identifier)) {

}

IdentifierExpression::~IdentifierExpression() = default;

void IdentifierExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
