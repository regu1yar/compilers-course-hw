#include "plus_expression.h"

PlusExpression::PlusExpression(
    Expression *first_operand,
    Expression *second_operand,
    const yy::location &location
    ) : first_operand(first_operand),
        second_operand(second_operand),
        location(location) {

}
