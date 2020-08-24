#include "statement_list.h"

void StatementList::pushBack(Statement *statement) {
  statements.push_back(statement);
}

void StatementList::pushFront(Statement *statement) {
  statements.push_front(statement);
}

void StatementList::accept(Visitor *visitor) {
  visitor->visit(this);
}

StatementList::~StatementList() {
  for (auto& statement : statements) {
    delete statement;
  }
}
