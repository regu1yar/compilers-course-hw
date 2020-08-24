#pragma once

#include "statement.h"
#include "expression.h"

class PrintStatement : public Statement {
 public:
  explicit PrintStatement(Expression* expression);

  ~PrintStatement() override;

  void accept(Visitor* visitor) override;
  int scopeCount() const override;

 public:
  Expression* expression;
};


