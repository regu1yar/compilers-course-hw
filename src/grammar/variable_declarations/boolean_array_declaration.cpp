#include "boolean_array_declaration.h"

#include <utility>

BooleanArrayDeclaration::BooleanArrayDeclaration(std::string identifier, const yy::location &location)
    : identifier(std::move(identifier))
    , location(location) {

}
