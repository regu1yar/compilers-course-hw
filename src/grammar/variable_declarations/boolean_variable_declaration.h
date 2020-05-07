#pragma once

#include <string>

#include "variable_declaration.h"

#include "location.hh"

class BooleanVariableDeclaration : public VariableDeclaration {
 public:
  BooleanVariableDeclaration(std::string identifier, const yy::location& location);

  ~BooleanVariableDeclaration() override = default;

 public:
  std::string identifier;
  yy::location location;
};
