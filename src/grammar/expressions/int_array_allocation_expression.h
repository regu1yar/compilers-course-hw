#pragma once

#include "expression.h"

#include "location.hh"

class IntArrayAllocationExpression : public Expression {
 public:
  IntArrayAllocationExpression(Expression* expression, const yy::location& location);

  ~IntArrayAllocationExpression() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* array_size;
};
