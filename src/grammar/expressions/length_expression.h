#pragma once

#include "expression.h"

#include "location.hh"

class LengthExpression : public Expression {
 public:
  LengthExpression(Expression* expression, const yy::location& location);

  ~LengthExpression();

 public:
  Expression* expression;
  yy::location location;
};
