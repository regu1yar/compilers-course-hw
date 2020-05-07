#pragma once

#include "expression.h"

#include "location.hh"

class BooleanValueExpression : public Expression {
 public:
  BooleanValueExpression(bool value, const yy::location& location);

  ~BooleanValueExpression() override;

  void accept(Visitor* visitor) override;

 public:
  bool value;
  yy::location location;
};


