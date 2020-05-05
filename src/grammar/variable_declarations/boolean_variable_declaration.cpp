#include "boolean_variable_declaration.h"

#include <utility>

BooleanVariableDeclaration::BooleanVariableDeclaration(std::string identifier, const yy::location &location)
    : identifier(std::move(identifier))
    , location(location) {

}
