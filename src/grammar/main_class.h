#pragma once

#include <string>

#include "statement_list.h"

class MainClass {
 public:
  MainClass(const std::string& class_name, StatementList* statements);

 private:
  std::string class_name_;
  StatementList* statements_;
};


