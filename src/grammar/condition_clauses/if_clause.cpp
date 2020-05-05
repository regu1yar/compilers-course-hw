#include "if_clause.h"

IfClause::IfClause(Expression *condition, Statement *body)
    : condition(condition)
    , body{body) {

}
