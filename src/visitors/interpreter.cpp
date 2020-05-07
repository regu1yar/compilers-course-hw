#include "interpreter.h"

#include "elements.h"

Interpreter::~Interpreter() {

}

void Interpreter::visit(Program *program) {
  program->main_class->accept(this);
}

void Interpreter::visit(MainClass *main_class) {
  main_class->statements->accept(this);
}

void Interpreter::visit(OrExpression *expression) {

}
