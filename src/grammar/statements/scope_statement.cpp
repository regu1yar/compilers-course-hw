#include "scope_statement.h"

ScopeStatement::ScopeStatement(StatementList *statements)
    : statements(statements) {

}

ScopeStatement::~ScopeStatement() {
  delete statements;
}

void ScopeStatement::accept(Visitor *visitor) {
  visitor->visit(this);
}
