#include "array_element_expression.h"

#include <utility>

ArrayElementExpression::ArrayElementExpression(
    std::string identifier,
    Expression *index_expression,
    const yy::location &location
    ) : identifier(std::move(identifier)),
        index_expression(index_expression),
        location(location) {

}
