#pragma once

#include <deque>

#include "statement.h"

class StatementList {
 public:
  void pushBack(Statement* statement);
  void pushFront(Statement* statement);

 private:
  std::deque<Statement*> statements_;

};


