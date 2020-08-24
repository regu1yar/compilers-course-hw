#pragma once

#include "statement.h"
#include "variable_declaration.h"

class VariableDeclarationStatement : public Statement {
 public:
  explicit VariableDeclarationStatement(VariableDeclaration* variable_declaration);

  ~VariableDeclarationStatement() override;

  void accept(Visitor* visitor) override;
  int scopeCount() const override;

 public:
  VariableDeclaration* variable_declaration;
};


