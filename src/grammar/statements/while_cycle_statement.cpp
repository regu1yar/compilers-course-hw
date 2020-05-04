#include "while_cycle_statement.h"

WhileCycleStatement::WhileCycleStatement(Expression *condition, Statement *cycle_body)
    : condition_(condition), cycle_body_(cycle_body) {

}
