#pragma once

#include <string>

#include "assignment.h"
#include "expression.h"

class VariableAssignment : public Assignment {
 public:
  VariableAssignment(std::string identifier, Expression* value);

  virtual ~VariableAssignment();

 public:
  std::string identifier;
  Expression* value;
};


