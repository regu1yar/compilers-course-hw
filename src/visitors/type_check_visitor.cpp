#include "type_check_visitor.h"

#include "elements.h"
#include "scope_layer.h"
#include "types.h"

TypeCheckVisitor::TypeCheckVisitor(ScopeLayer *global_layer) : TemplateVisitor<Type>(global_layer) {

}

TypeCheckVisitor::~TypeCheckVisitor() = default;

std::vector<CompilationError> TypeCheckVisitor::runCheck(Program *program) {
  program->accept(this);
  return errors_;
}

void TypeCheckVisitor::visit(Program *program) {
  program->main_class->accept(this);
}

void TypeCheckVisitor::visit(MainClass *main_class) {
  openScope();
  main_class->statements->accept(this);
  closeScope();
}

void TypeCheckVisitor::visit(OrExpression *expression) {
  verifyExpressionType(expression->first_operand, Type::BOOLEAN);
  verifyExpressionType(expression->second_operand, Type::BOOLEAN);
  tos_value_ = Type::BOOLEAN;
}

void TypeCheckVisitor::visit(AndExpression *expression) {
  verifyExpressionType(expression->first_operand, Type::BOOLEAN);
  verifyExpressionType(expression->second_operand, Type::BOOLEAN);
  tos_value_ = Type::BOOLEAN;
}

void TypeCheckVisitor::visit(PrintStatement *statement) {
  verifyExpressionType(statement->expression, Type::INT);
}

void TypeCheckVisitor::visit(ScopeStatement *statement) {
  openScope();
  statement->statements->accept(this);
  closeScope();
}

void TypeCheckVisitor::visit(StatementList *statements) {
  for (auto* statement : statements->statements) {
    statement->accept(this);
  }
}

void TypeCheckVisitor::visit(AssertStatement *statement) {
  statement->expression->accept(this);
}

void TypeCheckVisitor::visit(IfClause *condition_clause) {
  verifyExpressionType(condition_clause->condition, Type::BOOLEAN);
  condition_clause->body->accept(this);
}

void TypeCheckVisitor::visit(LessExpression *expression) {
  verifyExpressionType(expression->first_operand, Type::INT);
  verifyExpressionType(expression->second_operand, Type::INT);
  tos_value_ = Type::BOOLEAN;
}

void TypeCheckVisitor::visit(PlusExpression *expression) {
  verifyExpressionType(expression->first_operand, Type::INT);
  verifyExpressionType(expression->second_operand, Type::INT);
  tos_value_ = Type::INT;
}

void TypeCheckVisitor::visit(StarExpression *expression) {
  verifyExpressionType(expression->first_operand, Type::INT);
  verifyExpressionType(expression->second_operand, Type::INT);
  tos_value_ = Type::INT;
}

void TypeCheckVisitor::visit(MinusExpression *expression) {
  verifyExpressionType(expression->first_operand, Type::INT);
  verifyExpressionType(expression->second_operand, Type::INT);
  tos_value_ = Type::INT;
}

void TypeCheckVisitor::visit(SlashExpression *expression) {
  verifyExpressionType(expression->first_operand, Type::INT);
  verifyExpressionType(expression->second_operand, Type::INT);
  tos_value_ = Type::INT;
}

void TypeCheckVisitor::visit(EqualsExpression *expression) {
  verifyExpressionType(expression->first_operand, Type::INT);
  verifyExpressionType(expression->second_operand, Type::INT);
  tos_value_ = Type::BOOLEAN;
}

void TypeCheckVisitor::visit(LengthExpression *expression) {
  verifyExpressionType(expression->expression, {Type::INT_ARRAY, Type::BOOLEAN_ARRAY});
  tos_value_ = Type::INT;
}

void TypeCheckVisitor::visit(GreaterExpression *expression) {
  verifyExpressionType(expression->first_operand, Type::INT);
  verifyExpressionType(expression->second_operand, Type::INT);
  tos_value_ = Type::BOOLEAN;
}

void TypeCheckVisitor::visit(PercentExpression *expression) {
  verifyExpressionType(expression->first_operand, Type::INT);
  verifyExpressionType(expression->second_operand, Type::INT);
  tos_value_ = Type::INT;
}

void TypeCheckVisitor::visit(AssignmentStatement *statement) {
  statement->assignment->accept(this);
}

void TypeCheckVisitor::visit(IfElseClause *condition_clause) {
  verifyExpressionType(condition_clause->condition, Type::BOOLEAN);
  condition_clause->if_body->accept(this);
  condition_clause->else_body->accept(this);
}

void TypeCheckVisitor::visit(IntValueExpression *expression) {
  tos_value_ = Type::INT;
}

void TypeCheckVisitor::visit(NegationExpression *expression) {
  verifyExpressionType(expression->operand, Type::BOOLEAN);
  tos_value_ = Type::BOOLEAN;
}

void TypeCheckVisitor::visit(VariableAssignment *assignment) {
  verifyExpressionType(assignment->value, current_layer_->getVariableType(assignment->identifier));
}

void TypeCheckVisitor::visit(WhileCycleStatement *statement) {
  verifyExpressionType(statement->condition, Type::BOOLEAN);
  statement->cycle_body->accept(this);
}

void TypeCheckVisitor::visit(IdentifierExpression *expression) {
  tos_value_ = current_layer_->getVariableType(expression->identifier);
}

void TypeCheckVisitor::visit(IntArrayDeclaration *declaration) {

}

void TypeCheckVisitor::visit(ArrayElementAssignment *assignment) {
  verifyExpressionType(assignment->element_index, Type::INT);
  verifyExpressionType(
      assignment->value,
      getCorrespondedArrayType(current_layer_->getVariableType(assignment->identifier))
      );
}

void TypeCheckVisitor::visit(ArrayElementExpression *expression) {
  verifyExpressionType(expression->index_expression, Type::INT);
  tos_value_ = getCorrespondedArrayType(current_layer_->getVariableType(expression->identifier));
}

void TypeCheckVisitor::visit(BooleanArrayAllocationExpression *expression) {
  verifyExpressionType(expression->array_size, Type::INT);
  tos_value_ = Type::BOOLEAN_ARRAY;
}

void TypeCheckVisitor::visit(BooleanValueExpression *expression) {
  tos_value_ = Type::BOOLEAN;
}

void TypeCheckVisitor::visit(IntArrayAllocationExpression *expression) {
  verifyExpressionType(expression->array_size, Type::INT);
  tos_value_ = Type::INT_ARRAY;
}

void TypeCheckVisitor::visit(ParenthesesExpression *expression) {
  tos_value_ = accept(expression->expression);
}

void TypeCheckVisitor::visit(UnaryMinusExpression *expression) {
  verifyExpressionType(expression->operand, Type::INT);
  tos_value_ = Type::INT;
}

void TypeCheckVisitor::visit(ConditionClauseStatement *statement) {
  statement->condition_clause->accept(this);
}

void TypeCheckVisitor::visit(VariableDeclarationStatement *statement) {

}

void TypeCheckVisitor::visit(BooleanArrayDeclaration *declaration) {

}

void TypeCheckVisitor::visit(BooleanVariableDeclaration *declaration) {

}

void TypeCheckVisitor::visit(IntVariableDeclaration *declaration) {

}

void TypeCheckVisitor::verifyExpressionType(Expression* expression, Type expected_type) {
  Type actual_type = accept(expression);
  if (actual_type != expected_type) {
    errors_.emplace_back(
        "Type mismatch: expression has type " + toString(actual_type) + ", expected: " + toString(expected_type),
        expression->location.begin.line,
        expression->location.begin.column
    );
  }
}

void TypeCheckVisitor::verifyExpressionType(Expression *expression, const std::unordered_set<Type>& expected_types) {
  Type actual_type = accept(expression);
  if (expected_types.find(actual_type) == expected_types.end()) {
    errors_.emplace_back(
        "Type mismatch: expression has type " + toString(actual_type) +
        ", expected one of types: " + constructExpectedTypesString(expected_types),
        expression->location.begin.line,
        expression->location.begin.column
    );
  }
}

std::string TypeCheckVisitor::constructExpectedTypesString(const std::unordered_set<Type> &expected_types) {
  auto expected_type = expected_types.begin();
  std::string expected_string = toString(*expected_type);
  ++expected_type;
  while (expected_type != expected_types.end()) {
    expected_string += ", " + toString(*expected_type);
    ++expected_type;
  }

  return expected_string;
}

Type TypeCheckVisitor::getCorrespondedArrayType(Type array_type) {
  switch (array_type) {
    case Type::INT_ARRAY:
      return Type::INT;
    case Type::BOOLEAN_ARRAY:
      return Type::BOOLEAN;
    default:
      throw std::runtime_error("Unexpected array type: " + toString(array_type));
  }
}
