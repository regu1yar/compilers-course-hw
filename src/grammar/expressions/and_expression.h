#pragma once

#include "expression.h"

#include "location.hh"

class AndExpression : public Expression {
 public:
  AndExpression(Expression* first_operand, Expression* second_operand, const yy::location& location);

  ~AndExpression() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* first_operand;
  Expression* second_operand;
};
