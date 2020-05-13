#pragma once

#include "forward_decl.h"

class Visitor {
 public:
  virtual ~Visitor() = 0;

  virtual void visit(ArrayElementAssignment* assignment) = 0;
  virtual void visit(VariableAssignment* assignment) = 0;

  virtual void visit(IfClause* condition_clause) = 0;
  virtual void visit(IfElseClause* condition_clause) = 0;

  virtual void visit(AndExpression* expression) = 0;
  virtual void visit(ArrayElementExpression* expression) = 0;
  virtual void visit(BooleanArrayAllocationExpression* expression) = 0;
  virtual void visit(BooleanValueExpression* expression) = 0;
  virtual void visit(EqualsExpression* expression) = 0;
  virtual void visit(GreaterExpression* expression) = 0;
  virtual void visit(IdentifierExpression* expression) = 0;
  virtual void visit(IntArrayAllocationExpression* expression) = 0;
  virtual void visit(IntValueExpression* expression) = 0;
  virtual void visit(LengthExpression* expression) = 0;
  virtual void visit(LessExpression* expression) = 0;
  virtual void visit(MinusExpression* expression) = 0;
  virtual void visit(NegationExpression* expression) = 0;
  virtual void visit(OrExpression* expression) = 0;
  virtual void visit(ParenthesesExpression* expression) = 0;
  virtual void visit(PercentExpression* expression) = 0;
  virtual void visit(PlusExpression* expression) = 0;
  virtual void visit(SlashExpression* expression) = 0;
  virtual void visit(StarExpression* expression) = 0;
  virtual void visit(UnaryMinusExpression* expression) = 0;

  virtual void visit(AssertStatement* statement) = 0;
  virtual void visit(AssignmentStatement* statement) = 0;
  virtual void visit(ConditionClauseStatement* statement) = 0;
  virtual void visit(PrintStatement* statement) = 0;
  virtual void visit(ScopeStatement* statement) = 0;
  virtual void visit(VariableDeclarationStatement* statement) = 0;
  virtual void visit(WhileCycleStatement* statement) = 0;

  virtual void visit(BooleanArrayDeclaration* declaration) = 0;
  virtual void visit(BooleanVariableDeclaration* declaration) = 0;
  virtual void visit(IntArrayDeclaration* declaration) = 0;
  virtual void visit(IntVariableDeclaration* declaration) = 0;

  virtual void visit(MainClass* main_class) = 0;
  virtual void visit(Program* program) = 0;
  virtual void visit(StatementList* statements) = 0;
};
