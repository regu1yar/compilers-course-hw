#pragma once

#include "expression.h"

#include "location.hh"

class IntArrayAllocationExpression : public Expression {
 public:
  IntArrayAllocationExpression(Expression* expression, const yy::location& location);

  virtual ~IntArrayAllocationExpression();

 public:
  Expression* array_size;
  yy::location location;
};
