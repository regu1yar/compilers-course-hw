#pragma once

#include "statement.h"
#include "condition_clause.h"

class ConditionClauseStatement : public Statement {
 public:
  virtual ~ConditionClauseStatement();

  explicit ConditionClauseStatement(ConditionClause* condition_clause);

 public:
  ConditionClause* condition_clause;
};


