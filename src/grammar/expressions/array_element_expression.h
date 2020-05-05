#pragma once

#include <string>

#include "expression.h"

#include "location.hh"

class ArrayElementExpression : public Expression {
 public:
  ArrayElementExpression(std::string identifier, Expression* index_expression, const yy::location& location);

  virtual ~ArrayElementExpression();

 public:
  std::string identifier;
  Expression* index_expression;
  yy::location location;
};


