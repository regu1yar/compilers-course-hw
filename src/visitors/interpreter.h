#pragma once

#include "visitor.h"

class Interpreter : public Visitor {
 public:
  virtual ~Interpreter();

  virtual void visit(ArrayElementAssignment* assignment);
  virtual void visit(VariableAssignment* assignment);

  virtual void visit(IfClause* condition_clause);
  virtual void visit(IfElseClause* condition_clause);

  virtual void visit(AndExpression* expression);
  virtual void visit(ArrayElementExpression* expression);
  virtual void visit(BooleanArrayAllocationExpression* expression);
  virtual void visit(BooleanValueExpression* expression);
  virtual void visit(EqualsExpression* expression);
  virtual void visit(GreaterExpression* expression);
  virtual void visit(IdentifierExpression* expression);
  virtual void visit(IntArrayAllocationExpression* expression);
  virtual void visit(IntValueExpression* expression);
  virtual void visit(LengthExpression* expression);
  virtual void visit(LessExpression* expression);
  virtual void visit(MinusExpression* expression);
  virtual void visit(NegationExpression* expression);
  virtual void visit(OrExpression* expression);
  virtual void visit(ParenthesesExpression* expression);
  virtual void visit(PercentExpression* expression);
  virtual void visit(PlusExpression* expression);
  virtual void visit(SlashExpression* expression);
  virtual void visit(StarExpression* expression);
  virtual void visit(UnaryMinusExpression* expression);

  virtual void visit(AssertStatement* statement);
  virtual void visit(AssignmentStatement* statement);
  virtual void visit(ConditionClauseStatement* statement);
  virtual void visit(PrintStatement* statement);
  virtual void visit(ScopeStatement* statement);
  virtual void visit(VariableDeclarationStatement* statement);
  virtual void visit(WhileCycleStatement* statement);

  virtual void visit(BooleanArrayDeclaration* declaration);
  virtual void visit(BooleanVariableDeclaration* declaration);
  virtual void visit(IntArrayDeclaration* declaration);
  virtual void visit(IntVariableDeclaration* declaration);

  virtual void visit(MainClass* main_class);
  void visit(Program* program) override;
  virtual void visit(StatementList* statements);
};
