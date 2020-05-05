#pragma once

#include "condition_clause.h"
#include "expression.h"
#include "statement.h"

class IfElseClause : public ConditionClause {
 public:
  IfElseClause(Expression* condition, Statement* if_body, Statement* else_body);

  virtual ~IfElseClause();

 public:
  Expression* condition;
  Statement* if_body;
  Statement* else_body;
};


