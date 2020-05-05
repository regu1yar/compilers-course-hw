#pragma once

#include "statement.h"
#include "expression.h"

class WhileCycleStatement : public Statement {
 public:
  virtual ~WhileCycleStatement();

  WhileCycleStatement(Expression* condition, Statement* cycle_body);

 public:
  Expression* condition;
  Statement* cycle_body
  ;
};


