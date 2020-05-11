#pragma once

#include <string>

#include "variable_declaration.h"

#include "location.hh"

class BooleanVariableDeclaration : public VariableDeclaration {
 public:
  BooleanVariableDeclaration(std::string identifier, const yy::location& location);

  ~BooleanVariableDeclaration() override = default;

  void accept(Visitor* visitor) override;

 public:
  std::string identifier;
  yy::location location;
};
