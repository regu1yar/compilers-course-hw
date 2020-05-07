#include "print_statement.h"

PrintStatement::PrintStatement(Expression *expression)
    : expression(expression) {

}
PrintStatement::~PrintStatement() {
  delete expression;
}

void PrintStatement::accept(Visitor *visitor) {
  visitor->visit(this);
}
