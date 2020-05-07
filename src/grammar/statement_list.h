#pragma once

#include <deque>

#include "base_tree_element.h"
#include "statement.h"

class StatementList : public BaseTreeElement {
 public:
  void pushBack(Statement* statement);
  void pushFront(Statement* statement);

  ~StatementList() override = default;

  void accept(Visitor* visitor) override;

 public:
  std::deque<Statement*> statements;
};


