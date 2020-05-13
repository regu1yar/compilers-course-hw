#pragma once

#include "statement.h"

class EmptyStatement : public Statement {
 public:
  ~EmptyStatement() override;

  void accept(Visitor* visitor) override;
};


