#pragma once

#include <string>

#include "variable_declaration.h"

#include "location.hh"

class IntArrayDeclaration : public VariableDeclaration {
 public:
  IntArrayDeclaration(std::string identifier, const yy::location& location);

  ~IntArrayDeclaration() override = default;

 public:
  std::string identifier;
  yy::location location;
};
