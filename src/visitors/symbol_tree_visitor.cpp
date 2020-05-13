#include "symbol_tree_visitor.h"

#include "elements.h"
#include "scope_layer.h"
#include "types.h"

SymbolTreeVisitor::~SymbolTreeVisitor() = default;

void SymbolTreeVisitor::visit(Program *program) {
  program->main_class->accept(this);
}

void SymbolTreeVisitor::visit(MainClass *main_class) {
  current_layer_ = new ScopeLayer(current_layer_);

  main_class->statements->accept(this);

  current_layer_ = current_layer_->getParent();
}

void SymbolTreeVisitor::visit(OrExpression *expression) {
  expression->first_operand->accept(this);
  expression->second_operand->accept(this);
}

void SymbolTreeVisitor::visit(AndExpression *expression) {
  expression->first_operand->accept(this);
  expression->second_operand->accept(this);
}

void SymbolTreeVisitor::visit(PrintStatement *statement) {
  statement->expression->accept(this);
}

void SymbolTreeVisitor::visit(ScopeStatement *statement) {
  current_layer_ = new ScopeLayer(current_layer_);

  statement->statements->accept(this);

  current_layer_ = current_layer_->getParent();
}

void SymbolTreeVisitor::visit(StatementList *statements) {
  for (auto* statement : statements->statements) {
    statement->accept(this);
  }
}

void SymbolTreeVisitor::visit(AssertStatement *statement) {
  statement->expression->accept(this);
}

void SymbolTreeVisitor::visit(IfClause *condition_clause) {
  condition_clause->condition->accept(this);
  condition_clause->body->accept(this);
}

void SymbolTreeVisitor::visit(LessExpression *expression) {
  expression->first_operand->accept(this);
  expression->second_operand->accept(this);
}

void SymbolTreeVisitor::visit(PlusExpression *expression) {
  expression->first_operand->accept(this);
  expression->second_operand->accept(this);
}

void SymbolTreeVisitor::visit(StarExpression *expression) {
  expression->first_operand->accept(this);
  expression->second_operand->accept(this);
}

void SymbolTreeVisitor::visit(MinusExpression *expression) {
  expression->first_operand->accept(this);
  expression->second_operand->accept(this);
}

void SymbolTreeVisitor::visit(SlashExpression *expression) {
  expression->first_operand->accept(this);
  expression->second_operand->accept(this);
}

void SymbolTreeVisitor::visit(EqualsExpression *expression) {
  expression->first_operand->accept(this);
  expression->second_operand->accept(this);
}

void SymbolTreeVisitor::visit(LengthExpression *expression) {
  expression->expression->accept(this);
}

void SymbolTreeVisitor::visit(GreaterExpression *expression) {
  expression->first_operand->accept(this);
  expression->second_operand->accept(this);
}

void SymbolTreeVisitor::visit(PercentExpression *expression) {
  expression->first_operand->accept(this);
  expression->second_operand->accept(this);
}

void SymbolTreeVisitor::visit(AssignmentStatement *statement) {
  statement->assignment->accept(this);
}

void SymbolTreeVisitor::visit(IfElseClause *condition_clause) {
  condition_clause->condition->accept(this);
  condition_clause->if_body->accept(this);
  condition_clause->else_body->accept(this);
}

void SymbolTreeVisitor::visit(IntValueExpression *expression) {

}

void SymbolTreeVisitor::visit(NegationExpression *expression) {
  expression->operand->accept(this);
}

void SymbolTreeVisitor::visit(VariableAssignment *assignment) {
  current_layer_->verifyIfVariableIsDeclared(assignment->identifier);

  assignment->value->accept(this);
}

void SymbolTreeVisitor::visit(WhileCycleStatement *statement) {
  statement->condition->accept(this);
  statement->cycle_body->accept(this);
}

void SymbolTreeVisitor::visit(IdentifierExpression *expression) {
//  current_layer_->verifyIfVariableIsInitialized(expression->identifier);
}

void SymbolTreeVisitor::visit(IntArrayDeclaration *declaration) {
  current_layer_->declareVariable(declaration->identifier, Type::INT_ARRAY);
}

void SymbolTreeVisitor::visit(ArrayElementAssignment *assignment) {
  current_layer_->verifyIfVariableIsDeclared(assignment->identifier);

  assignment->element_index->accept(this);
  assignment->value->accept(this);
}

void SymbolTreeVisitor::visit(ArrayElementExpression *expression) {
//  current_layer_->verifyIfVariableIsInitialized(expression->identifier);

  expression->index_expression->accept(this);
}

void SymbolTreeVisitor::visit(BooleanArrayAllocationExpression *expression) {
  expression->array_size->accept(this);
}

void SymbolTreeVisitor::visit(BooleanValueExpression *expression) {

}

void SymbolTreeVisitor::visit(IntArrayAllocationExpression *expression) {
  expression->array_size->accept(this);
}

void SymbolTreeVisitor::visit(ParenthesesExpression *expression) {
  expression->expression->accept(this);
}

void SymbolTreeVisitor::visit(UnaryMinusExpression *expression) {
  expression->operand->accept(this);
}

void SymbolTreeVisitor::visit(ConditionClauseStatement *statement) {
  statement->condition_clause->accept(this);
}

void SymbolTreeVisitor::visit(VariableDeclarationStatement *statement) {
  statement->variable_declaration->accept(this);
}

void SymbolTreeVisitor::visit(BooleanArrayDeclaration *declaration) {
  current_layer_->declareVariable(declaration->identifier, Type::BOOLEAN_ARRAY);
}

void SymbolTreeVisitor::visit(BooleanVariableDeclaration *declaration) {
  current_layer_->declareVariable(declaration->identifier, Type::BOOLEAN);
}

void SymbolTreeVisitor::visit(IntVariableDeclaration *declaration) {
  current_layer_->declareVariable(declaration->identifier, Type::INT);
}

ScopeLayer *SymbolTreeVisitor::buildSymbolTree(Program *program) {
  current_layer_ = new ScopeLayer();
  program->accept(this);
  return current_layer_;
}
