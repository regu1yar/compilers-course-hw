#pragma once

#include <string>

#include "variable_declaration.h"

#include "location.hh"

class IntVariableDeclaration : public VariableDeclaration {
 public:
  IntVariableDeclaration(std::string identifier, const yy::location& location);

  virtual ~IntVariableDeclaration();

 public:
  std::string identifier;
  yy::location location;
};
