#include "if_else_clause.h"

IfElseClause::IfElseClause(Expression *condition, Statement *if_body, Statement *else_body)
  : condition(condition)
  , if_body(if_body)
  , else_body(else_body) {

}

IfElseClause::~IfElseClause() {
  delete condition;
  delete if_body;
  delete else_body;
}

void IfElseClause::accept(Visitor *visitor) {
  visitor->visit(this);
}
