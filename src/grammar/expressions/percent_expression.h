#pragma once

#include "expression.h"

#include "location.hh"

class PercentExpression : public Expression {
 public:
  PercentExpression(Expression* first_operand, Expression* second_operand, const yy::location& location);

  ~PercentExpression() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* first_operand;
  Expression* second_operand;
};


