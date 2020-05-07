#include "main_class.h"

MainClass::MainClass(const std::string &class_name, StatementList *statements)
    : class_name(class_name)
    , statements(statements) {

}

MainClass::~MainClass() {

}

void MainClass::accept(Visitor *visitor) {
  visitor->visit(this);
}
