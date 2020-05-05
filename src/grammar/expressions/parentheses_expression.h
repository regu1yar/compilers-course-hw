#pragma once

#include "expression.h"

class ParenthesesExpression : public Expression {
  explicit ParenthesesExpression(Expression* expression);

 public:
  Expression* expression;
};


