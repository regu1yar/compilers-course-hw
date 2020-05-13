#pragma once

#include "statement.h"
#include "expression.h"

class WhileCycleStatement : public Statement {
 public:
  WhileCycleStatement(Expression* condition, Statement* cycle_body);

  ~WhileCycleStatement() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* condition;
  Statement* cycle_body;
};
