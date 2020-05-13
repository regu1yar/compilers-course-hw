#include "condition_clause_statement.h"

ConditionClauseStatement::ConditionClauseStatement(ConditionClause *condition_clause)
    : condition_clause(condition_clause) {

}

ConditionClauseStatement::~ConditionClauseStatement() {
  delete condition_clause;
}

void ConditionClauseStatement::accept(Visitor *visitor) {
  visitor->visit(this);
}
