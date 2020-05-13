#include "template_visitor.h"

template<typename T>
TemplateVisitor<T>::TemplateVisitor(ScopeLayer *global_layer) : current_layer_(global_layer) {
  if (current_layer_ == nullptr) {
    throw std::runtime_error("Build symbol tree first");
  }
  offsets_.push(0);
}

template TemplateVisitor<Type>::TemplateVisitor(ScopeLayer* global_layer);
template TemplateVisitor<std::shared_ptr<BasicType>>::TemplateVisitor(ScopeLayer* global_layer);

template<typename T>
TemplateVisitor<T>::~TemplateVisitor() = default;

template TemplateVisitor<Type>::~TemplateVisitor();
template TemplateVisitor<std::shared_ptr<BasicType>>::~TemplateVisitor();

template<typename T>
T TemplateVisitor<T>::accept(BaseTreeElement *element) {
  element->accept(this);
  return tos_value_;
}

template Type TemplateVisitor<Type>::accept(BaseTreeElement *element);
template std::shared_ptr<BasicType> TemplateVisitor<std::shared_ptr<BasicType>>::accept(BaseTreeElement *element);

template<typename T>
void TemplateVisitor<T>::openScope() {
  current_layer_ = current_layer_->getChild(offsets_.top());

  offsets_.push(0);
}

template void TemplateVisitor<Type>::openScope();
template void TemplateVisitor<std::shared_ptr<BasicType>>::openScope();

template<typename T>
void TemplateVisitor<T>::closeScope() {
  offsets_.pop();
  size_t next_scope_offset = offsets_.top() + 1;
  offsets_.pop();
  offsets_.push(next_scope_offset);

  current_layer_ = current_layer_->getParent();
}

template void TemplateVisitor<Type>::closeScope();
template void TemplateVisitor<std::shared_ptr<BasicType>>::closeScope();
