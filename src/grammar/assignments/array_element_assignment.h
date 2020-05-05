#pragma once

#include <string>

#include "assignment.h"
#include "expression.h"

class ArrayElementAssignment : public Assignment {
 public:
  ArrayElementAssignment(std::string identifier, Expression* element_index, Expression* value);

  virtual ~ArrayElementAssignment();

 public:
  std::string identifier;
  Expression* element_index;
  Expression* value;
};


