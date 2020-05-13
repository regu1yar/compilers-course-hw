#pragma once

#include "base_tree_element.h"

class VariableDeclaration : public virtual BaseTreeElement {
 public:
  ~VariableDeclaration() override = 0;
};
