#pragma once

#include "expression.h"

#include "location.hh"

class BooleanArrayAllocationExpression : public Expression {
 public:
  BooleanArrayAllocationExpression(Expression* expression, const yy::location& location);

  ~BooleanArrayAllocationExpression() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* array_size;
  yy::location location;
};
