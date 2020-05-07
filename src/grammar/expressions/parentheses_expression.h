#pragma once

#include "expression.h"

class ParenthesesExpression : public Expression {
  explicit ParenthesesExpression(Expression* expression);

  ~ParenthesesExpression() override;

  void accept(Visitor* visitor) override;

 public:
  Expression* expression;
};


