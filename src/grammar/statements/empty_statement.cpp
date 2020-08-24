#include "empty_statement.h"

EmptyStatement::~EmptyStatement() = default;

void EmptyStatement::accept(Visitor *visitor) {

}

int EmptyStatement::scopeCount() const {
  return 0;
}
