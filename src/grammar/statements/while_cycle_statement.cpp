#include "while_cycle_statement.h"

WhileCycleStatement::WhileCycleStatement(Expression *condition, Statement *cycle_body)
    : condition(condition), cycle_body(cycle_body) {

}

WhileCycleStatement::~WhileCycleStatement() {
  delete condition;
  delete cycle_body;
}

void WhileCycleStatement::accept(Visitor *visitor) {
  visitor->visit(this);
}
