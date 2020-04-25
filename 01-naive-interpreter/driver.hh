#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fstream>

#include "scanner.h"
#include "parser.hh"
#include "exceptions.h"
#include "compilation_error.h"
#include "runtime_error.h"

class Driver {
 public:
  explicit Driver(bool trace_parsing = false, bool trace_scanning = false);
  ~Driver() = default;

  int Parse(const std::string& f);

  const yy::location& getParserLocation() const;

  void initRuntimeError(const RuntimeError& error);
  void addCompilationError(const CompilationError& error);

  int getIntVariableValue(const std::string& name) const ;
  bool getBooleanVariableValue(const std::string& name) const;

  void declareIntVariable(const std::string& name);
  void declareBooleanVariable(const std::string& name);

  void setIntVariableValue(const std::string& name, int value);
  void setBooleanVariableValue(const std::string& name, bool value);

 private:
  enum TYPE {
    INT,
    BOOLEAN
  };

 private:
  void verifyVariableType(const std::string& name, TYPE type) const;
  void verifyIfVariableIsUndeclared(const std::string& name) const;

  void reportRuntimeError(std::ostream& es) const;
  void reportCompilationErrors(std::ostream& es) const;

  void ScanBegin();
  void ScanEnd();

  void clearErrors();
  void clearVariables();

  static std::unordered_map<TYPE, std::string> initTypeMapping() {
    std::unordered_map<TYPE, std::string> mapping;
    mapping[INT] = "int";
    mapping[BOOLEAN] = "boolean";
    return mapping;
  }

 private:
  bool trace_parsing_;
  bool trace_scanning_;

  friend class Scanner;
  Scanner scanner_;

  yy::parser parser_;
  RuntimeError* runtime_error_;

  std::string file_;
  std::ifstream stream_;
  yy::location location_;
  std::unordered_map<std::string, TYPE> variable_name_to_type_;
  std::unordered_map<std::string, int> int_variables_;
  std::unordered_map<std::string, bool> boolean_variables_;
  std::unordered_map<std::string, std::vector<int>*> int_array_variables_;
  std::unordered_map<std::string, std::vector<bool>*> boolean_array_variables_;
  std::vector<CompilationError> compilation_errors_;

  static const std::unordered_map<TYPE, std::string> TYPE_STRINGS_;
};
