#include "array_element_assignment.h"

#include <utility>

ArrayElementAssignment::ArrayElementAssignment(
    std::string identifier,
    Expression *element_index,
    Expression *value
    ) : identifier(std::move(identifier)),
        element_index(element_index),
        value(value) {

}

ArrayElementAssignment::~ArrayElementAssignment() {
  delete element_index;
  delete value;
}

void ArrayElementAssignment::accept(Visitor *visitor) {
  visitor->visit(this);
}
