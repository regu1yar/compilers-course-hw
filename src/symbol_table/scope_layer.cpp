#include "scope_layer.h"

#include <utility>

#include "exceptions.h"

ScopeLayer::ScopeLayer(ScopeLayer *parent) : parent_(parent) {
  if (parent_ != nullptr) {
    parent_->addChild(this);
  }
}

ScopeLayer::~ScopeLayer() {
  for (auto& child : children_) {
    delete child;
  }
}

void ScopeLayer::addChild(ScopeLayer *child) {
  children_.push_back(child);
}

ScopeLayer *ScopeLayer::getParent() const {
  return parent_;
}

ScopeLayer * ScopeLayer::getChild(size_t offset) const {
  return children_[offset];
}

void ScopeLayer::declareVariable(const std::string &name, Type type) {
  if (isDeclared(name)) {
    throw DoubleDeclarationException("Such variable has already been declared: " + name);
  }

  variable_types_[name] = type;
}

void ScopeLayer::setVariableValue(const std::string &name, std::shared_ptr<BasicType> value) {
  ScopeLayer* current_layer = this;
  while (current_layer != nullptr && !current_layer->isDeclared(name)) {
    current_layer = current_layer->parent_;
  }

  if (current_layer == nullptr) {
    throw UndeclaredVariableException("No such variable declared: " + name);
  }

  current_layer->verifyVariableType(name, value->getType());
  current_layer->variable_values_[name] = std::move(value);
}

std::shared_ptr<BasicType> ScopeLayer::getVariableValue(const std::string &name) const {
  auto* current_layer = const_cast<ScopeLayer *>(this);
  while (current_layer != nullptr && !current_layer->isDeclared(name)) {
    current_layer = current_layer->parent_;
  }

  if (current_layer == nullptr) {
    throw UndeclaredVariableException("No such variable declared: " + name);
  } else if (!current_layer->isInitialized(name)) {
    throw UninitializedVariableException("Variable isn't initialized: " + name);
  }

  return current_layer->variable_values_[name];
}

std::shared_ptr<BasicType> ScopeLayer::getVariableValueMutable(const std::string &name) {
  auto* current_layer = this;
  while (current_layer != nullptr && !current_layer->isDeclared(name)) {
    current_layer = current_layer->parent_;
  }

  if (current_layer == nullptr) {
    throw UndeclaredVariableException("No such variable declared: " + name);
  } else if (!current_layer->isInitialized(name)) {
    throw UninitializedVariableException("Variable isn't initialized: " + name);
  }

  return current_layer->variable_values_[name];
}

bool ScopeLayer::isDeclared(const std::string &name) const {
  return variable_types_.find(name) != variable_types_.end();
}

void ScopeLayer::verifyVariableType(const std::string& name, Type type) const {
  auto var_type = variable_types_.find(name);
  if (var_type == variable_types_.end()) {
    throw UndeclaredVariableException("No such variable declared: " + name);
  } else if (var_type->second != type) {
    throw TypeMismatchException("Variable " + name + " has type " + toString(var_type->second) + ", expected: " + toString(type));
  }
}

void ScopeLayer::verifyVariableType(const std::string &name, const std::shared_ptr<BasicType>& type) const {
  verifyVariableType(name, type->getType());
}

void ScopeLayer::verifyIfVariableIsDeclared(const std::string &name) const {
  auto* current_layer = const_cast<ScopeLayer *>(this);
  while (current_layer != nullptr && !current_layer->isDeclared(name)) {
    current_layer = current_layer->parent_;
  }

  if (current_layer == nullptr) {
    throw UndeclaredVariableException("No such variable declared: " + name);
  }
}
bool ScopeLayer::isInitialized(const std::string &name) const {
  return variable_values_.find(name) != variable_values_.end();
}

void ScopeLayer::verifyIfVariableIsInitialized(const std::string &name) const {
  auto* current_layer = const_cast<ScopeLayer *>(this);
  while (current_layer != nullptr && !current_layer->isDeclared(name)) {
    current_layer = current_layer->parent_;
  }

  if (current_layer == nullptr) {
    throw UndeclaredVariableException("No such variable declared: " + name);
  } else if (!current_layer->isInitialized(name)) {
    throw UninitializedVariableException("Variable isn't initialized: " + name);
  }
}

Type ScopeLayer::getVariableType(const std::string& name) const {
  auto* current_layer = const_cast<ScopeLayer *>(this);
  while (current_layer != nullptr && !current_layer->isDeclared(name)) {
    current_layer = current_layer->parent_;
  }

  if (current_layer == nullptr) {
    throw UndeclaredVariableException("No such variable declared: " + name);
  }

  return current_layer->variable_types_.at(name);
}
