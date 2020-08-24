#pragma once

#include "statement.h"
#include "expression.h"

#include "location.hh"

class AssertStatement : public Statement {
 public:
  AssertStatement(Expression* expression, const yy::location& location);

  ~AssertStatement() override;

  void accept(Visitor* visitor) override;
  int scopeCount() const override;

 public:
  Expression* expression;
  yy::location location;
};


