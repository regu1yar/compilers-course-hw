#include "interpreter.h"

#include "elements.h"

Interpreter::~Interpreter() {

}

void Interpreter::visit(Program *program) {
  program->main_class->accept(this);
}

void Interpreter::visit(MainClass *main_class) {
  main_class->statements->accept(this);
}

void Interpreter::visit(OrExpression *expression) {

}
void Interpreter::visit(ArrayElementAssignment *assignment) {

}
void Interpreter::visit(VariableAssignment *assignment) {

}
void Interpreter::visit(IfClause *condition_clause) {

}
void Interpreter::visit(IfElseClause *condition_clause) {

}
void Interpreter::visit(AndExpression *expression) {

}
void Interpreter::visit(ArrayElementExpression *expression) {

}
void Interpreter::visit(BooleanArrayAllocationExpression *expression) {

}
void Interpreter::visit(BooleanValueExpression *expression) {

}
void Interpreter::visit(EqualsExpression *expression) {

}
void Interpreter::visit(GreaterExpression *expression) {

}
void Interpreter::visit(IdentifierExpression *expression) {

}
void Interpreter::visit(IntArrayAllocationExpression *expression) {

}
void Interpreter::visit(IntValueExpression *expression) {

}
void Interpreter::visit(LengthExpression *expression) {

}
void Interpreter::visit(LessExpression *expression) {

}
void Interpreter::visit(MinusExpression *expression) {

}
void Interpreter::visit(NegationExpression *expression) {

}
void Interpreter::visit(ParenthesesExpression *expression) {

}
void Interpreter::visit(PercentExpression *expression) {

}
void Interpreter::visit(PlusExpression *expression) {

}
void Interpreter::visit(SlashExpression *expression) {

}
void Interpreter::visit(StarExpression *expression) {

}
void Interpreter::visit(UnaryMinusExpression *expression) {

}
void Interpreter::visit(AssertStatement *statement) {

}
void Interpreter::visit(AssignmentStatement *statement) {

}
void Interpreter::visit(ConditionClauseStatement *statement) {

}
void Interpreter::visit(PrintStatement *statement) {

}
void Interpreter::visit(ScopeStatement *statement) {

}
void Interpreter::visit(VariableDeclarationStatement *statement) {

}
void Interpreter::visit(WhileCycleStatement *statement) {

}
void Interpreter::visit(BooleanArrayDeclaration *declaration) {

}
void Interpreter::visit(BooleanVariableDeclaration *declaration) {

}
void Interpreter::visit(IntArrayDeclaration *declaration) {

}
void Interpreter::visit(IntVariableDeclaration *declaration) {

}
void Interpreter::visit(StatementList *statements) {

}
