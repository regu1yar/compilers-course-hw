#pragma once

#include "expression.h"

#include "location.hh"

class AndExpression : public Expression {
 public:
  AndExpression(Expression* first_operand, Expression* second_operand, const yy::location& location);

  virtual ~AndExpression();

 public:
  Expression* first_operand;
  Expression* second_operand;
  yy::location location;
};
