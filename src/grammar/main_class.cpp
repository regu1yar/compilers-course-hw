#include "main_class.h"

#include <utility>

MainClass::MainClass(std::string class_name, StatementList *statements)
    : class_name(std::move(class_name))
    , statements(statements) {

}

MainClass::~MainClass() = default;

void MainClass::accept(Visitor *visitor) {
  visitor->visit(this);
}
