#pragma once

#include <string>

#include "expression.h"

#include "location.hh"

class ArrayElementExpression : public Expression {
 public:
  ArrayElementExpression(std::string identifier, Expression* index_expression, const yy::location& location);

  ~ArrayElementExpression() override;

  void accept(Visitor* visitor) override;

 public:
  std::string identifier;
  Expression* index_expression;
};


