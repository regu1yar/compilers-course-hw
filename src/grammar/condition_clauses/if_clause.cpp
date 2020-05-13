#include "if_clause.h"

IfClause::IfClause(Expression *condition, Statement *body)
    : condition(condition)
    , body(body) {

}

IfClause::~IfClause() {
  delete condition;
  delete body;
}

void IfClause::accept(Visitor *visitor) {
  visitor->visit(this);
}
