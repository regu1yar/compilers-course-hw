#include "assert_statement.h"

AssertStatement::AssertStatement(Expression *expression, const yy::location &location)
    : expression(expression)
    , location(location) {

}
