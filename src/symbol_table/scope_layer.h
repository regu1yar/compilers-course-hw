#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "basic_type.h"

class ScopeLayer {
 public:
  explicit ScopeLayer(ScopeLayer* parent = nullptr);

  ~ScopeLayer();

  ScopeLayer* getParent() const;
  ScopeLayer* getChild(size_t offset) const;

  void declareVariable(const std::string& name, Type type);
  void setVariableValue(const std::string& name, std::shared_ptr<BasicType> value);
  std::shared_ptr<BasicType> getVariableValue(const std::string& name) const;
  std::shared_ptr<BasicType> getVariableValueMutable(const std::string& name);
  Type getVariableType(const std::string& name) const;

  void verifyVariableType(const std::string& name, Type type) const;
  void verifyVariableType(const std::string& name, const std::shared_ptr<BasicType>& type) const;
  void verifyIfVariableIsDeclared(const std::string& name) const;
  void verifyIfVariableIsInitialized(const std::string& name) const;

 private:
  void addChild(ScopeLayer* child);

  bool isDeclared(const std::string& name) const;
  bool isInitialized(const std::string& name) const;

 private:
  ScopeLayer* parent_;
  std::vector<ScopeLayer*> children_;
  std::unordered_map<std::string, Type> variable_types_;
  std::unordered_map<std::string, std::shared_ptr<BasicType>> variable_values_;
};


