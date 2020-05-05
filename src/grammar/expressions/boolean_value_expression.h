#pragma once

#include "expression.h"

#include "location.hh"

class BooleanValueExpression : public Expression {
 public:
  BooleanValueExpression(bool value, const yy::location& location);

  virtual ~BooleanValueExpression();

 public:
  bool value;
  yy::location location;
};


