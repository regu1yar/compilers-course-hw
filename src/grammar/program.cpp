#include "program.h"

Program::Program(MainClass *main_class)
    : main_class(main_class) {

}

Program::~Program() {
  delete main_class;
}

void Program::accept(Visitor *visitor) {
  visitor->visit(this);
}
