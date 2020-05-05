#pragma once

#include "expression.h"

#include "location.hh"

class NegationExpression : public Expression {
 public:
  NegationExpression(Expression* operand, const yy::location& location);

  ~NegationExpression();

 public:
  Expression* operand;
  yy::location location;
};
