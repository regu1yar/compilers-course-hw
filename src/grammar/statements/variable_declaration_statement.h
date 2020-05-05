#pragma once

#include "statement.h"
#include "variable_declaration.h"

class VariableDeclarationStatement : public Statement {
 public:
  virtual ~VariableDeclarationStatement();

  explicit VariableDeclarationStatement(VariableDeclaration* variable_declaration);

 public:
  VariableDeclaration* variable_declaration;
};


