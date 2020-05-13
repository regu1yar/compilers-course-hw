#pragma once

#include <string>
#include <fstream>

#include "visitor.h"

class PrintVisitor : public Visitor {
 public:
  explicit PrintVisitor(const std::string& filename);

  ~PrintVisitor() override;

  void printAST(Program *program);

  void visit(ArrayElementAssignment* assignment) override;
  void visit(VariableAssignment* assignment) override;

  void visit(IfClause* condition_clause) override;
  void visit(IfElseClause* condition_clause) override;

  void visit(AndExpression* expression) override;
  void visit(ArrayElementExpression* expression) override;
  void visit(BooleanArrayAllocationExpression* expression) override;
  void visit(BooleanValueExpression* expression) override;
  void visit(EqualsExpression* expression) override;
  void visit(GreaterExpression* expression) override;
  void visit(IdentifierExpression* expression) override;
  void visit(IntArrayAllocationExpression* expression) override;
  void visit(IntValueExpression* expression) override;
  void visit(LengthExpression* expression) override;
  void visit(LessExpression* expression) override;
  void visit(MinusExpression* expression) override;
  void visit(NegationExpression* expression) override;
  void visit(OrExpression* expression) override;
  void visit(ParenthesesExpression* expression) override;
  void visit(PercentExpression* expression) override;
  void visit(PlusExpression* expression) override;
  void visit(SlashExpression* expression) override;
  void visit(StarExpression* expression) override;
  void visit(UnaryMinusExpression* expression) override;

  void visit(AssertStatement* statement) override;
  void visit(AssignmentStatement* statement) override;
  void visit(ConditionClauseStatement* statement) override;
  void visit(PrintStatement* statement) override;
  void visit(ScopeStatement* statement) override;
  void visit(VariableDeclarationStatement* statement) override;
  void visit(WhileCycleStatement* statement) override;

  void visit(BooleanArrayDeclaration* declaration) override;
  void visit(BooleanVariableDeclaration* declaration) override;
  void visit(IntArrayDeclaration* declaration) override;
  void visit(IntVariableDeclaration* declaration) override;

  void visit(MainClass* main_class) override;
  void visit(Program* program) override;
  void visit(StatementList* statements) override;

 private:
  void printTabs();

 private:
  std::ofstream stream_;
  size_t tabs_{0};
};


