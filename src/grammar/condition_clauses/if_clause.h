#pragma once

#include "condition_clause.h"
#include "expression.h"
#include "statement.h"

class IfClause : public ConditionClause {
 public:
  IfClause(Expression* condition, Statement* body);

  ~IfClause() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* condition;
  Statement* body;
};


