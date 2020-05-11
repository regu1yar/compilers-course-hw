#pragma once

#include "base_tree_element.h"

class Statement : public virtual BaseTreeElement {
 public:
  ~Statement() override = 0;
};
