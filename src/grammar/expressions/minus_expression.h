#pragma once

#include "expression.h"

#include "location.hh"

class MinusExpression : public Expression {
 public:
  MinusExpression(Expression* first_operand, Expression* second_operand, const yy::location& location);

  virtual ~MinusExpression();

 public:
  Expression* first_operand;
  Expression* second_operand;
  yy::location location;
};


