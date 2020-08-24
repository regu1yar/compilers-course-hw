#pragma once

#include "statement.h"
#include "statement_list.h"

class ScopeStatement : public Statement {
 public:
  explicit ScopeStatement(StatementList* statements);

  ~ScopeStatement() override;

  void accept(Visitor* visitor) override;
  int scopeCount() const override;

 public:
  StatementList* statements;
};


