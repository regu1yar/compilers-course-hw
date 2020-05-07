#pragma once

#include "base_tree_element.h"
#include "main_class.h"

class Program : public BaseTreeElement {
 public:
  explicit Program(MainClass* main_class);

  ~Program() override;

  void accept(Visitor* visitor) override;

 public:
  MainClass* main_class;
};


