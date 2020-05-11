#pragma once

#include <string>

#include "variable_declaration.h"

#include "location.hh"

class IntArrayDeclaration : public VariableDeclaration {
 public:
  IntArrayDeclaration(std::string identifier, const yy::location& location);

  ~IntArrayDeclaration() override = default;

  void accept(Visitor* visitor) override;

 public:
  std::string identifier;
  yy::location location;
};
