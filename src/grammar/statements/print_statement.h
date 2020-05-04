#pragma once

#include "statement.h"
#include "expression.h"

class PrintStatement : public Statement {
 public:
  virtual ~PrintStatement();

  explicit PrintStatement(Expression* expression);

 private:
  Expression* expression_
};


