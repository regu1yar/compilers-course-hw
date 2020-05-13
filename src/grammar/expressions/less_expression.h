#pragma once

#include "expression.h"

#include "location.hh"

class LessExpression : public Expression {
 public:
  LessExpression(Expression* first_operand, Expression* second_operand, const yy::location& location);

  ~LessExpression() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* first_operand;
  Expression* second_operand;
};
