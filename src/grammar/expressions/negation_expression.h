#pragma once

#include "expression.h"

#include "location.hh"

class NegationExpression : public Expression {
 public:
  NegationExpression(Expression* operand, const yy::location& location);

  ~NegationExpression() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* operand;
};
