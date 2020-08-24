#pragma once

#include "statement.h"
#include "condition_clauses/condition_clause.h"

class ConditionClauseStatement : public Statement {
 public:
  explicit ConditionClauseStatement(ConditionClause* condition_clause);

  ~ConditionClauseStatement() override;

  void accept(Visitor* visitor) override;
  int scopeCount() const override;

 public:
  ConditionClause* condition_clause;
};


