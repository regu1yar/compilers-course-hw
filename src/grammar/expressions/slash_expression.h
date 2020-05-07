#pragma once

#include "expression.h"

#include "location.hh"

class SlashExpression : public Expression {
 public:
  SlashExpression(Expression* first_operand, Expression* second_operand, const yy::location& location);

  ~SlashExpression() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* first_operand;
  Expression* second_operand;
  yy::location location;
};


