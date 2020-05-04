#include "assert_statement.h"

AssertStatement::AssertStatement(Expression *expression, const yy::location &location)
    : expression_(expression)
    , location_(location) {

}
