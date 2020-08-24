#pragma once

#include "statement.h"

class ConditionClause : public virtual Statement {
 public:
  ~ConditionClause() override = 0;
};
