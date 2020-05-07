#pragma once

#include "statement.h"
#include "assignment.h"

class AssignmentStatement : public Statement {
 public:
  explicit AssignmentStatement(Assignment* assignment);

  ~AssignmentStatement() override;

  void accept(Visitor* visitor) override;

 public:
  Assignment* assignment;
};


