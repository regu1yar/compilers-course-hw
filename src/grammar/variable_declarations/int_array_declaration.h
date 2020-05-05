#pragma once

#include <string>

#include "variable_declaration.h"

#include "location.hh"

class IntArrayDeclaration : public VariableDeclaration {
 public:
  IntArrayDeclaration(std::string identifier, const yy::location& location);

  virtual ~IntArrayDeclaration();

 public:
  std::string identifier;
  yy::location location;
};
