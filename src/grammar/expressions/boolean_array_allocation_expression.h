#pragma once

#include "expression.h"

#include "location.hh"

class BooleanArrayAllocationExpression : public Expression {
 public:
  BooleanArrayAllocationExpression(Expression* expression, const yy::location& location);

  virtual ~BooleanArrayAllocationExpression();

 public:
  Expression* array_size;
  yy::location location;
};
