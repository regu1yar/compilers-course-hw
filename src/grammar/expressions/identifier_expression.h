#pragma once

#include <string>

#include "expression.h"

#include "location.hh"

class IdentifierExpression : public Expression {
 public:
  IdentifierExpression(std::string identifier, const yy::location& location);

  virtual ~IdentifierExpression();

 public:
  std::string identifier;
  yy::location location;
};


