#pragma once

#include "expression.h"

#include "location.hh"

class GreaterExpression : public Expression {
 public:
  GreaterExpression(Expression* first_operand, Expression* second_operand, const yy::location& location);

  virtual ~GreaterExpression();

 public:
  Expression* first_operand;
  Expression* second_operand;
  yy::location location;
};
