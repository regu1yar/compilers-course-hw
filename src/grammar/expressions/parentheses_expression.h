#pragma once

#include "expression.h"

#include "location.hh"

class ParenthesesExpression : public Expression {
 public:
  explicit ParenthesesExpression(Expression* expression, const yy::location& location);

  ~ParenthesesExpression() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* expression;
};


