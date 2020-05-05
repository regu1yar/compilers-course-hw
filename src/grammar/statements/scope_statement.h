#pragma once

#include "statement.h"
#include "statement_list.h"

class ScopeStatement : public Statement {
 public:
  virtual ~ScopeStatement();

  explicit ScopeStatement(StatementList* statements);

 public:
  StatementList* statements;
};


