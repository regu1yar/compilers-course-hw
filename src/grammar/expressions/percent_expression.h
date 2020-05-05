#pragma once

#include "expression.h"

#include "location.hh"

class PercentExpression : public Expression {
 public:
  PercentExpression(Expression* first_operand, Expression* second_operand, const yy::location& location);

  virtual ~PercentExpression();

 public:
  Expression* first_operand;
  Expression* second_operand;
  yy::location location;
};


