#pragma once

#include "statement.h"
#include "expression.h"

class PrintStatement : public Statement {
 public:
  explicit PrintStatement(Expression* expression);

  ~PrintStatement() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* expression;
};


