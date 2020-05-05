#pragma once

#include "expression.h"

#include "location.hh"

class StarExpression : public Expression {
 public:
  StarExpression(Expression* first_operand, Expression* second_operand, const yy::location& location);

  virtual ~StarExpression();

 public:
  Expression* first_operand;
  Expression* second_operand;
  yy::location location;
};


