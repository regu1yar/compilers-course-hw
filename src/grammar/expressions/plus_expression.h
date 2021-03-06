#pragma once

#include "expression.h"

#include "location.hh"

class PlusExpression : public Expression {
 public:
  PlusExpression(Expression* first_operand, Expression* second_operand, const yy::location& location);

  ~PlusExpression() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* first_operand;
  Expression* second_operand;
};
