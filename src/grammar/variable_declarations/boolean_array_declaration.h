#pragma once

#include <string>

#include "variable_declaration.h"

#include "location.hh"

class BooleanArrayDeclaration : public VariableDeclaration {
 public:
  BooleanArrayDeclaration(std::string identifier, const yy::location& location);

  virtual ~BooleanArrayDeclaration();

 public:
  std::string identifier;
  yy::location location;
};
