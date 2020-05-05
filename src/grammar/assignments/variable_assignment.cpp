#include "variable_assignment.h"

#include <utility>

VariableAssignment::VariableAssignment(std::string identifier, Expression* value)
    : identifier(std::move(identifier))
    , value(value) {

}
