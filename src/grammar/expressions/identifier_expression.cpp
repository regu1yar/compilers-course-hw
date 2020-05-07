#include "identifier_expression.h"

#include <utility>

IdentifierExpression::IdentifierExpression(std::string identifier, const yy::location &location)
    : identifier(std::move(identifier))
    , location(location) {

}

IdentifierExpression::~IdentifierExpression() {

}

void IdentifierExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
