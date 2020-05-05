#include "identifier_expression.h"

#include <utility>

IdentifierExpression::IdentifierExpression(std::string identifier, const yy::location &location)
    : identifier(std::move(identifier))
    , location(location) {

}
