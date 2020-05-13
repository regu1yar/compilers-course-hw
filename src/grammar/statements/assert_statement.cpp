#include "assert_statement.h"

AssertStatement::AssertStatement(Expression *expression, const yy::location &location)
    : expression(expression)
    , location(location) {

}

AssertStatement::~AssertStatement() {
  delete expression;
}

void AssertStatement::accept(Visitor *visitor) {
  visitor->visit(this);
}
