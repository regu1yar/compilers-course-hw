#pragma once

#include "base_tree_element.h"

class Expression : public virtual BaseTreeElement {
 public:
  ~Expression() override = 0;
};
