#pragma once

#include "base_tree_element.h"

#include "location.hh"

class Expression : public virtual BaseTreeElement {
 public:
  explicit Expression(const yy::location& location);

  ~Expression() override = 0;

 public:
  yy::location location;
};
