#pragma once

#include "visitor.h"

class BaseTreeElement {
 public:
  virtual ~BaseTreeElement() = 0;

  virtual void accept(Visitor* visitor) = 0;
};


