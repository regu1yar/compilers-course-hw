#include "int_array_declaration.h"

#include <utility>

IntArrayDeclaration::IntArrayDeclaration(std::string identifier, const yy::location &location)
    : identifier(std::move(identifier))
    , location(location) {

}
