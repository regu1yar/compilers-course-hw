#pragma once

#include "expression.h"

#include "location.hh"

class UnaryMinusExpression : public Expression {
 public:
  UnaryMinusExpression(Expression* operand, const yy::location& location);

  ~UnaryMinusExpression();

 public:
  Expression* operand;
  yy::location location;
};
