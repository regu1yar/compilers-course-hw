#pragma once

#include "main_class.h"

class Program {
 public:
  explicit Program(MainClass* main_class);

 private:
  MainClass* main_class_;
};


