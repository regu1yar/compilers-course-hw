#include "variable_declaration_statement.h"

VariableDeclarationStatement::VariableDeclarationStatement(VariableDeclaration *variable_declaration)
    : variable_declaration(variable_declaration) {

}

VariableDeclarationStatement::~VariableDeclarationStatement() {
  delete variable_declaration;
}

void VariableDeclarationStatement::accept(Visitor *visitor) {
  visitor->visit(this);
}

int VariableDeclarationStatement::scopeCount() const {
  return 0;
}
