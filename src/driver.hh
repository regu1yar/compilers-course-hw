#pragma once

#include <fstream>

#include "scanner.h"
#include "parser.hh"
#include "compilation_error.h"
#include "scope_layer.h"
#include "visitors.h"

class Driver {
 public:
  explicit Driver(bool trace_parsing = false, bool trace_scanning = false);
  ~Driver();

  int Parse(const std::string& f);

  const yy::location& getParserLocation() const;
  yy::location getParserLocation();

  void ScanBegin();
  void ScanEnd();

  void setProgram(Program* program);

  void printAST() const;
  void buildSymbolTree();
  void runTypeCheck();
  void interpret();

 private:
  bool trace_parsing_;
  bool trace_scanning_;

  friend class Scanner;
  Scanner scanner_;

  yy::parser parser_;

  std::string file_;
  std::ifstream stream_;
  yy::location location_;
  Program* program_{nullptr};

  ScopeLayer* global_layer_{nullptr};
};
