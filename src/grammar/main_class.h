#pragma once

#include <string>

#include "base_tree_element.h"
#include "statement_list.h"

class MainClass : public BaseTreeElement {
 public:
  MainClass(const std::string& class_name, StatementList* statements);

  ~MainClass() override;

  void accept(Visitor* visitor) override;

 public:
  std::string class_name;
  StatementList* statements;
};


