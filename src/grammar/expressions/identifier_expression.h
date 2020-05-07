#pragma once

#include <string>

#include "expression.h"

#include "location.hh"

class IdentifierExpression : public Expression {
 public:
  IdentifierExpression(std::string identifier, const yy::location& location);

  ~IdentifierExpression() override;

  void accept(Visitor* visitor) override;

 public:
  std::string identifier;
  yy::location location;
};


