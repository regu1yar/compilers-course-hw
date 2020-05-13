#include "assignment_statement.h"

AssignmentStatement::AssignmentStatement(Assignment *assignment)
    : assignment(assignment) {

}

AssignmentStatement::~AssignmentStatement() {
  delete assignment;
}

void AssignmentStatement::accept(Visitor *visitor) {
  visitor->visit(this);
}
