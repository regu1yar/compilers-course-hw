#include "while_cycle_statement.h"

WhileCycleStatement::WhileCycleStatement(Expression *condition, Statement *cycle_body)
    : condition(condition), cycle_body(cycle_body) {

}
