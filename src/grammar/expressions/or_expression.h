#pragma once

#include "expression.h"

#include "location.hh"

class OrExpression : public Expression {
 public:
  OrExpression(Expression* first_operand, Expression* second_operand, const yy::location& location);

  ~OrExpression() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* first_operand;
  Expression* second_operand;
};
