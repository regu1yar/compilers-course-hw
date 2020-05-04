#include "statement_list.h"

void StatementList::pushBack(Statement *statement) {
  statements_.push_back(statement);
}

void StatementList::pushFront(Statement *statement) {
  statements_.push_front(statement);
}
