#include <iostream>

#include "driver.hh"
#include "parser.hh"

const std::unordered_map<Driver::TYPE, std::string> Driver::TYPE_STRINGS_ = Driver::initTypeMapping();

Driver::Driver(bool trace_parsing, bool trace_scanning)
    : trace_parsing_(trace_parsing)
    , trace_scanning_(trace_scanning)
    , scanner_(*this)
    , parser_(scanner_, *this)
    , runtime_error_(nullptr)
{ }

int Driver::Parse(const std::string& f) {
  file_ = f;
  location_.initialize(&file_);
  ScanBegin();
  parser_.set_debug_level(trace_parsing_);
  int res = parser_();
  ScanEnd();
  return res;
}

void Driver::ScanBegin() {
  scanner_.set_debug(trace_scanning_);
  if (file_.empty() || file_ == "-") {
  } else {
    stream_.open(file_);
    std::cout << file_ << std::endl;
    scanner_.yyrestart(&stream_);
  }
}

void Driver::ScanEnd() {
  reportCompilationErrors(std::cerr);
  reportRuntimeError(std::cerr);

  clearErrors();
  clearVariables();

  stream_.close();
}

const yy::location &Driver::getParserLocation() const {
  return location_;
}

void Driver::initRuntimeError(const RuntimeError &error) {
  if (runtime_error_ == nullptr) {
    runtime_error_ = new RuntimeError(error);
  }
}

void Driver::addCompilationError(const CompilationError &error) {
  compilation_errors_.emplace_back(error);
}

int Driver::getIntVariableValue(const std::string &name) const {
  verifyVariableType(name, INT);
  return int_variables_.at(name);
}

bool Driver::getBooleanVariableValue(const std::string &name) const {
  verifyVariableType(name, BOOLEAN);
  return boolean_variables_.at(name);
}

void Driver::declareIntVariable(const std::string &name) {
  verifyIfVariableIsUndeclared(name);
  variable_name_to_type_[name] = INT;
}

void Driver::declareBooleanVariable(const std::string &name) {
  verifyIfVariableIsUndeclared(name);
  variable_name_to_type_[name] = BOOLEAN;
}

void Driver::setIntVariableValue(const std::string &name, int value) {
  verifyVariableType(name, INT);
  int_variables_[name] = value;
}

void Driver::setBooleanVariableValue(const std::string &name, bool value) {
  verifyVariableType(name, BOOLEAN);
  boolean_variables_[name] = value;
}

void Driver::verifyVariableType(const std::string &name, Driver::TYPE type) const {
  auto var_type = variable_name_to_type_.find(name);
  if (var_type == variable_name_to_type_.end()) {
    throw UndeclaredVariableException("No such variable declared: " + name);
  } else if (var_type->second != type) {
    throw TypeMismatchException("Variable " + name + " has type " + TYPE_STRINGS_.at(var_type->second) +
        ", expected: " + TYPE_STRINGS_.at(type));
  }
}

void Driver::verifyIfVariableIsUndeclared(const std::string &name) const {
  auto var_type = variable_name_to_type_.find(name);
  if (var_type != variable_name_to_type_.end()) {
    throw DoubleDeclarationException("Such variable has already been declared: " + name);
  }
}

void Driver::reportRuntimeError(std::ostream& es) const {
  if (runtime_error_ != nullptr) {
    es << runtime_error_->toString() << std::endl;
  }
}

void Driver::reportCompilationErrors(std::ostream &es) const {
  for (const auto& compilationError : compilation_errors_) {
    es << compilationError.toString() << std::endl;
  }
}

void Driver::clearErrors() {
  delete runtime_error_;
  runtime_error_ = nullptr;
  compilation_errors_.clear();
}

void Driver::clearVariables() {
  for (auto& int_arr : int_array_variables_) {
    delete int_arr.second;
  }
  for (auto& bool_arr : boolean_array_variables_) {
    delete bool_arr.second;
  }

  variable_name_to_type_.clear();
  int_variables_.clear();
  boolean_variables_.clear();
  int_array_variables_.clear();
  boolean_array_variables_.clear();
}
