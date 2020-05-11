#include "int_variable_declaration.h"

#include <utility>

IntVariableDeclaration::IntVariableDeclaration(std::string identifier, const yy::location &location)
    : identifier(std::move(identifier))
    , location(location) {

}

void IntVariableDeclaration::accept(Visitor *visitor) {
  visitor->visit(this);
}
