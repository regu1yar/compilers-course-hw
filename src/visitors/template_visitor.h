#pragma once

#include <stack>

#include "visitor.h"
#include "base_tree_element.h"
#include "scope_layer.h"

template<typename T>
class TemplateVisitor : public virtual Visitor {
 public:
  explicit TemplateVisitor(ScopeLayer* global_layer);

  ~TemplateVisitor() override = 0;

 protected:
  T accept(BaseTreeElement* element);

  void openScope();
  void closeScope();
  void shiftScope(int delta);

 protected:
  ScopeLayer* current_layer_;
  std::stack<size_t> offsets_;
  T tos_value_;
};


