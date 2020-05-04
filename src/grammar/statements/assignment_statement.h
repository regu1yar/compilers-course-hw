#pragma once

#include "statement.h"
#include "assignment.h"

class AssignmentStatement : public Statement {
 public:
  virtual ~AssignmentStatement();

  explicit AssignmentStatement(Assignment* assignment);

 private:
  Assignment* assignment_;
};


