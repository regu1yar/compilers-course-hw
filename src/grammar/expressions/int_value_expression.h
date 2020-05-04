#pragma once

#include "expression.h"

#include "location.hh"

class IntValueExpression : public Expression {
 public:
  IntValueExpression(int value, const yy::location& location);

  virtual ~IntValueExpression();

  virtual ExpressionType getType();

  virtual int evaluateInt() const;
  virtual bool evaluateBoolean() const;

 private:
  int value_;
  yy::location location_;
};


