#pragma once

#include <string>

#include "variable_declaration.h"

#include "location.hh"

class BooleanArrayDeclaration : public VariableDeclaration {
 public:
  BooleanArrayDeclaration(std::string identifier, const yy::location& location);

  ~BooleanArrayDeclaration() override = default;

  void accept(Visitor* visitor) override;

 public:
  std::string identifier;
  yy::location location;
};
