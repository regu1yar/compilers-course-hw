#include "print_visitor.h"

#include "elements.h"

PrintVisitor::PrintVisitor(const std::string &filename) : stream_(filename) {

}

PrintVisitor::~PrintVisitor() {
  stream_.close();
}

void PrintVisitor::printAST(Program *program) {
  program->accept(this);
}

void PrintVisitor::visit(Program *program) {
  stream_ << "Program:" << std::endl;
  ++tabs_;

  program->main_class->accept(this);

  --tabs_;
}

void PrintVisitor::visit(MainClass *main_class) {
  printTabs();
  stream_ << "MainClass:" << std::endl;
  ++tabs_;

  main_class->statements->accept(this);

  --tabs_;
}

void PrintVisitor::visit(OrExpression *expression) {
  printTabs();
  stream_ << "OrExpression:" << std::endl;
  ++tabs_;

  expression->first_operand->accept(this);
  expression->second_operand->accept(this);

  --tabs_;
}

void PrintVisitor::visit(AndExpression *expression) {
  printTabs();
  stream_ << "AndExpression:" << std::endl;
  ++tabs_;

  expression->first_operand->accept(this);
  expression->second_operand->accept(this);

  --tabs_;
}

void PrintVisitor::visit(PrintStatement *statement) {
  printTabs();
  stream_ << "PrintStatement:" << std::endl;
  ++tabs_;

  statement->expression->accept(this);

  --tabs_;
}

void PrintVisitor::visit(ScopeStatement *statement) {
  printTabs();
  stream_ << "ScopeStatement:" << std::endl;
  ++tabs_;

  statement->statements->accept(this);

  --tabs_;
}

void PrintVisitor::visit(StatementList *statements) {
  printTabs();
  stream_ << "StatementList:" << std::endl;
  ++tabs_;

  for (auto* statement : statements->statements) {
    statement->accept(this);
  }

  --tabs_;
}

void PrintVisitor::visit(AssertStatement *statement) {
  printTabs();
  stream_ << "AssertStatement:" << std::endl;
  ++tabs_;

  statement->expression->accept(this);

  --tabs_;
}

void PrintVisitor::visit(IfClause *condition_clause) {
  printTabs();
  stream_ << "IfClause:" << std::endl;
  ++tabs_;

  condition_clause->condition->accept(this);
  condition_clause->body->accept(this);

  --tabs_;
}

void PrintVisitor::visit(LessExpression *expression) {
  printTabs();
  stream_ << "LessExpression:" << std::endl;
  ++tabs_;

  expression->first_operand->accept(this);
  expression->second_operand->accept(this);

  --tabs_;
}

void PrintVisitor::visit(PlusExpression *expression) {
  printTabs();
  stream_ << "PlusExpression:" << std::endl;
  ++tabs_;

  expression->first_operand->accept(this);
  expression->second_operand->accept(this);

  --tabs_;
}

void PrintVisitor::visit(StarExpression *expression) {
  printTabs();
  stream_ << "StarExpression:" << std::endl;
  ++tabs_;

  expression->first_operand->accept(this);
  expression->second_operand->accept(this);

  --tabs_;
}

void PrintVisitor::visit(MinusExpression *expression) {
  printTabs();
  stream_ << "MinusExpression:" << std::endl;
  ++tabs_;

  expression->first_operand->accept(this);
  expression->second_operand->accept(this);

  --tabs_;
}

void PrintVisitor::visit(SlashExpression *expression) {
  printTabs();
  stream_ << "SlashExpression:" << std::endl;
  ++tabs_;

  expression->first_operand->accept(this);
  expression->second_operand->accept(this);

  --tabs_;
}

void PrintVisitor::visit(EqualsExpression *expression) {
  printTabs();
  stream_ << "EqualsExpression:" << std::endl;
  ++tabs_;

  expression->first_operand->accept(this);
  expression->second_operand->accept(this);

  --tabs_;
}

void PrintVisitor::visit(LengthExpression *expression) {
  printTabs();
  stream_ << "LengthExpression:" << std::endl;
  ++tabs_;

  expression->expression->accept(this);

  --tabs_;
}

void PrintVisitor::visit(GreaterExpression *expression) {
  printTabs();
  stream_ << "GreaterExpression:" << std::endl;
  ++tabs_;

  expression->first_operand->accept(this);
  expression->second_operand->accept(this);

  --tabs_;
}

void PrintVisitor::visit(PercentExpression *expression) {
  printTabs();
  stream_ << "PercentExpression:" << std::endl;
  ++tabs_;

  expression->first_operand->accept(this);
  expression->second_operand->accept(this);

  --tabs_;
}

void PrintVisitor::visit(AssignmentStatement *statement) {
  printTabs();
  stream_ << "AssignmentStatement:" << std::endl;
  ++tabs_;

  statement->assignment->accept(this);

  --tabs_;
}

void PrintVisitor::visit(IfElseClause *condition_clause) {
  printTabs();
  stream_ << "IfElseClause:" << std::endl;
  ++tabs_;

  condition_clause->condition->accept(this);
  condition_clause->if_body->accept(this);
  condition_clause->else_body->accept(this);

  --tabs_;
}

void PrintVisitor::visit(IntValueExpression *expression) {
  printTabs();
  stream_ << "IntValueExpression: " << expression->value << std::endl;
}

void PrintVisitor::visit(NegationExpression *expression) {
  printTabs();
  stream_ << "NegationExpression:" << std::endl;
  ++tabs_;

  expression->operand->accept(this);

  --tabs_;
}

void PrintVisitor::visit(VariableAssignment *assignment) {
  printTabs();
  stream_ << "VariableAssignment: " << assignment->identifier << std::endl;
  ++tabs_;

  assignment->value->accept(this);

  --tabs_;
}

void PrintVisitor::visit(WhileCycleStatement *statement) {
  printTabs();
  stream_ << "WhileCycleStatement:" << std::endl;
  ++tabs_;

  statement->condition->accept(this);
  statement->cycle_body->accept(this);

  --tabs_;
}

void PrintVisitor::visit(IdentifierExpression *expression) {
  printTabs();
  stream_ << "IdentifierExpression: " << expression->identifier << std::endl;
}

void PrintVisitor::visit(IntArrayDeclaration *declaration) {
  printTabs();
  stream_ << "IntArrayDeclaration: " << declaration->identifier << std::endl;
}

void PrintVisitor::visit(ArrayElementAssignment *assignment) {
  printTabs();
  stream_ << "ArrayElementAssignment: " << assignment->identifier << std::endl;
  ++tabs_;

  assignment->element_index->accept(this);
  assignment->value->accept(this);

  --tabs_;
}

void PrintVisitor::visit(ArrayElementExpression *expression) {
  printTabs();
  stream_ << "ArrayElementExpression: " << expression->identifier << std::endl;
  ++tabs_;

  expression->index_expression->accept(this);

  --tabs_;
}

void PrintVisitor::visit(BooleanArrayAllocationExpression *expression) {
  printTabs();
  stream_ << "BooleanArrayAllocationExpression:" << std::endl;
  ++tabs_;

  expression->array_size->accept(this);

  --tabs_;
}

void PrintVisitor::visit(BooleanValueExpression *expression) {
  printTabs();
  stream_ << "BooleanValueExpression: ";
  if (expression->value) {
    stream_ << "true" << std::endl;
  } else {
    stream_ << "false" << std::endl;
  }
}

void PrintVisitor::visit(IntArrayAllocationExpression *expression) {
  printTabs();
  stream_ << "IntArrayAllocationExpression:" << std::endl;
  ++tabs_;

  expression->array_size->accept(this);

  --tabs_;
}

void PrintVisitor::visit(ParenthesesExpression *expression) {
  printTabs();
  stream_ << "ParenthesesExpression:" << std::endl;
  ++tabs_;

  expression->expression->accept(this);

  --tabs_;
}

void PrintVisitor::visit(UnaryMinusExpression *expression) {
  printTabs();
  stream_ << "UnaryMinusExpression:" << std::endl;
  ++tabs_;

  expression->operand->accept(this);

  --tabs_;
}

void PrintVisitor::visit(ConditionClauseStatement *statement) {
  printTabs();
  stream_ << "ConditionClauseStatement:" << std::endl;
  ++tabs_;

  statement->condition_clause->accept(this);

  --tabs_;
}

void PrintVisitor::visit(VariableDeclarationStatement *statement) {
  printTabs();
  stream_ << "VariableDeclarationStatement:" << std::endl;
  ++tabs_;

  statement->variable_declaration->accept(this);

  --tabs_;
}

void PrintVisitor::visit(BooleanArrayDeclaration *declaration) {
  printTabs();
  stream_ << "BooleanArrayDeclarations: " << declaration->identifier << std::endl;
}

void PrintVisitor::visit(BooleanVariableDeclaration *declaration) {
  printTabs();
  stream_ << "BooleanVariableDeclaration: " << declaration->identifier << std::endl;}

void PrintVisitor::visit(IntVariableDeclaration *declaration) {
  printTabs();
  stream_ << "IntVariableDeclaration: " << declaration->identifier << std::endl;}

void PrintVisitor::printTabs() {
  for (size_t i = 0; i < tabs_; ++i) {
    stream_ << '\t';
  }
}
