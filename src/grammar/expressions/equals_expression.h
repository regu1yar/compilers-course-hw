#pragma once

#include "expression.h"

#include "location.hh"

class EqualsExpression : public Expression {
 public:
  EqualsExpression(Expression* first_operand, Expression* second_operand, const yy::location& location);

  ~EqualsExpression() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* first_operand;
  Expression* second_operand;
};
