#pragma once

#include "statement.h"
#include "expression.h"

#include "location.hh"

class AssertStatement : public Statement {
 public:
  virtual ~AssertStatement();

  AssertStatement(Expression* expression, const yy::location& location);

 private:
  Expression* expression_;
  yy::location location_;
};


