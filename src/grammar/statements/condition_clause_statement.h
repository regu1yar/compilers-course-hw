#pragma once

#include "statement.h"
#include "condition_clause.h"

class ConditionClauseStatement : public Statement {
 public:
  explicit ConditionClauseStatement(ConditionClause* condition_clause);

  ~ConditionClauseStatement() override;

  void accept(Visitor* visitor) override;

 public:
  ConditionClause* condition_clause;
};


