#pragma once

#include "condition_clause.h"
#include "expression.h"
#include "statement.h"

class IfElseClause : public ConditionClause {
 public:
  IfElseClause(Expression* condition, Statement* if_body, Statement* else_body);

  ~IfElseClause() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* condition;
  Statement* if_body;
  Statement* else_body;
};


