#pragma once

#include "expression.h"

#include "location.hh"

class IntValueExpression : public Expression {
 public:
  IntValueExpression(int value, const yy::location& location);

  virtual ~IntValueExpression();

 public:
  int value;
  yy::location location;
};
