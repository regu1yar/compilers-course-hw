#pragma once

#include "expression.h"

#include "location.hh"

class PlusExpression : public Expression {
 public:
  PlusExpression(Expression* first_operand, Expression* second_operand, const yy::location& location);

  virtual ~PlusExpression();

 public:
  Expression* first_operand;
  Expression* second_operand;
  yy::location location;
};
