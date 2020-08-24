#include "interpreter.h"

#include <iostream>

#include "elements.h"
#include "types.h"
#include "exceptions.h"

Interpreter::Interpreter(ScopeLayer *global_layer) : TemplateVisitor<std::shared_ptr<BasicType>>(global_layer) {}

Interpreter::~Interpreter() = default;

void Interpreter::run(Program* program) {
  try {
    program->accept(this);
  } catch (const AssertException& assert) {
    std::cerr << error_.toString() << std::endl;
  }
}

void Interpreter::visit(Program *program) {
  program->main_class->accept(this);
}

void Interpreter::visit(MainClass *main_class) {
  openScope();
  main_class->statements->accept(this);
  closeScope();
}

void Interpreter::visit(OrExpression *expression) {
  tos_value_ = std::make_shared<Boolean>(
      accept(expression->first_operand)->toBool() ||
          accept(expression->second_operand)->toBool()
      );
}

void Interpreter::visit(ArrayElementAssignment *assignment) {
  switch (current_layer_->getVariableType(assignment->identifier)) {
    case Type::INT_ARRAY:
      assignArrayElementValue<int>(assignment);
      break;
    case Type::BOOLEAN_ARRAY:
      assignArrayElementValue<bool>(assignment);
      break;
    default:
      throw std::runtime_error("Unexpected type: " + toString(current_layer_->getVariableType(assignment->identifier)));
  }
}

void Interpreter::visit(VariableAssignment *assignment) {
  current_layer_->setVariableValue(assignment->identifier, accept(assignment->value));
}

void Interpreter::visit(IfClause *condition_clause) {
  if (accept(condition_clause->condition)->toBool()) {
    condition_clause->body->accept(this);
  } else {
    shiftScope(condition_clause->body->scopeCount());
  }
}

void Interpreter::visit(IfElseClause *condition_clause) {
  if (accept(condition_clause->condition)->toBool()) {
    condition_clause->if_body->accept(this);
    shiftScope(condition_clause->else_body->scopeCount());
  } else {
    shiftScope(condition_clause->if_body->scopeCount());
    condition_clause->else_body->accept(this);
  }
}

void Interpreter::visit(AndExpression *expression) {
  tos_value_ = std::make_shared<Boolean>(
      accept(expression->first_operand)->toBool() &&
          accept(expression->second_operand)->toBool()
  );
}

void Interpreter::visit(ArrayElementExpression *expression) {
  switch (current_layer_->getVariableType(expression->identifier)) {
    case Type::INT_ARRAY:
      tos_value_ = getArrayElementValue<int>(expression);
      break;
    case Type::BOOLEAN_ARRAY:
      tos_value_ = getArrayElementValue<bool>(expression);
      break;
    default:
      throw std::runtime_error("Unexpected type: " + toString(current_layer_->getVariableType(expression->identifier)));
  }
}

void Interpreter::visit(BooleanArrayAllocationExpression *expression) {
  tos_value_ = std::make_shared<Array<bool>>(accept(expression->array_size)->toInt());
}

void Interpreter::visit(BooleanValueExpression *expression) {
  tos_value_ = std::make_shared<Boolean>(expression->value);
}

void Interpreter::visit(EqualsExpression *expression) {
  tos_value_ = std::make_shared<Boolean>(
      accept(expression->first_operand)->toInt() ==
          accept(expression->second_operand)->toInt()
  );
}

void Interpreter::visit(GreaterExpression *expression) {
  tos_value_ = std::make_shared<Boolean>(
      accept(expression->first_operand)->toInt() >
          accept(expression->second_operand)->toInt()
  );
}

void Interpreter::visit(IdentifierExpression *expression) {
  tos_value_ = current_layer_->getVariableValue(expression->identifier);
}

void Interpreter::visit(IntArrayAllocationExpression *expression) {
  tos_value_ = std::make_shared<Array<int>>(accept(expression->array_size)->toInt());
}

void Interpreter::visit(IntValueExpression *expression) {
  tos_value_ = std::make_shared<Int>(expression->value);
}

void Interpreter::visit(LengthExpression *expression) {
  auto array = accept(expression->expression);
  switch (array->getType()) {
    case Type::INT_ARRAY:
      tos_value_ = std::make_shared<Int>(std::dynamic_pointer_cast<Array<int>>(array)->getLength());
      break;
    case Type::BOOLEAN_ARRAY:
      tos_value_ = std::make_shared<Int>(std::dynamic_pointer_cast<Array<bool>>(array)->getLength());
      break;
    default:
      throw std::runtime_error("Unexpected array type: " + toString(array->getType()));
  }
}

void Interpreter::visit(LessExpression *expression) {
  tos_value_ = std::make_shared<Boolean>(
      accept(expression->first_operand)->toInt() <
          accept(expression->second_operand)->toInt()
  );
}

void Interpreter::visit(MinusExpression *expression) {
  tos_value_ = std::make_shared<Int>(
      accept(expression->first_operand)->toInt() -
          accept(expression->second_operand)->toInt()
  );
}

void Interpreter::visit(NegationExpression *expression) {
  tos_value_ = std::make_shared<Boolean>(!accept(expression->operand)->toBool());
}

void Interpreter::visit(ParenthesesExpression *expression) {
  tos_value_ = accept(expression->expression);
}

void Interpreter::visit(PercentExpression *expression) {
  tos_value_ = std::make_shared<Int>(
      accept(expression->first_operand)->toInt() %
          accept(expression->second_operand)->toInt()
  );
}

void Interpreter::visit(PlusExpression *expression) {
  tos_value_ = std::make_shared<Int>(
      accept(expression->first_operand)->toInt() +
          accept(expression->second_operand)->toInt()
  );
}

void Interpreter::visit(SlashExpression *expression) {
  tos_value_ = std::make_shared<Int>(
      accept(expression->first_operand)->toInt() /
          accept(expression->second_operand)->toInt()
  );
}

void Interpreter::visit(StarExpression *expression) {
  tos_value_ = std::make_shared<Int>(
      accept(expression->first_operand)->toInt() *
          accept(expression->second_operand)->toInt()
  );
}

void Interpreter::visit(UnaryMinusExpression *expression) {
  tos_value_ = std::make_shared<Int>(-accept(expression->operand)->toInt());
}

void Interpreter::visit(AssertStatement *statement) {
  auto value = accept(statement->expression);
  switch (value->getType()) {
    case Type::INT:
      if (!value->toInt()) {
        error_ = RuntimeError(
            "Assert",
            statement->expression->location.begin.line,
            statement->expression->location.begin.column
            );
        throw AssertException("Assert wasn't passed");
      }
      break;
    case Type::BOOLEAN_ARRAY:
      if (!value->toBool()) {
        error_ = RuntimeError(
            "Assert",
            statement->expression->location.begin.line,
            statement->expression->location.begin.column
            );
        throw AssertException("Assert wasn't passed");
      }
      break;
    default:
      throw std::runtime_error("Unexpected assert type: " + toString(value->getType()));
  }
}

void Interpreter::visit(AssignmentStatement *statement) {
  statement->assignment->accept(this);
}

void Interpreter::visit(ConditionClauseStatement *statement) {
  statement->condition_clause->accept(this);
}

void Interpreter::visit(PrintStatement *statement) {
  std::cout << accept(statement->expression)->toInt() << std::endl;
}

void Interpreter::visit(ScopeStatement *statement) {
  openScope();
  statement->statements->accept(this);
  closeScope();
}

void Interpreter::visit(VariableDeclarationStatement *statement) {

}

void Interpreter::visit(WhileCycleStatement *statement) {
  bool first_loop = true;
  while (accept(statement->condition)->toBool()) {
    if (!first_loop) {
      shiftScope(-statement->cycle_body->scopeCount());
    }

    statement->cycle_body->accept(this);
    first_loop = false;
  }
}

void Interpreter::visit(BooleanArrayDeclaration *declaration) {

}

void Interpreter::visit(BooleanVariableDeclaration *declaration) {

}

void Interpreter::visit(IntArrayDeclaration *declaration) {

}

void Interpreter::visit(IntVariableDeclaration *declaration) {

}

void Interpreter::visit(StatementList *statements) {
  for (auto& statement : statements->statements) {
    statement->accept(this);
  }
}

template<typename T>
void Interpreter::assignArrayElementValue(ArrayElementAssignment *assignment) {
  std::shared_ptr<Array<T>> array = std::dynamic_pointer_cast<Array<T>>(
      current_layer_->getVariableValueMutable(assignment->identifier)
      );
  auto value = accept(assignment->value);
  switch (value->getType()) {
    case Type::INT:
      array->setElementValue(accept(assignment->element_index)->toInt(), value->toInt());
      break;
    case Type::BOOLEAN:
      array->setElementValue(accept(assignment->element_index)->toInt(), value->toBool());
      break;
    default:
      throw std::runtime_error("Unexpected type: " + toString(value->getType()));
  }
}

template<typename T>
std::shared_ptr<BasicType> Interpreter::getArrayElementValue(ArrayElementExpression *expression) {
  std::shared_ptr<Array<T>> array = std::dynamic_pointer_cast<Array<T>>(
      current_layer_->getVariableValue(expression->identifier)
  );
  switch (array->getType()) {
    case Type::INT_ARRAY:
      return std::make_shared<Int>(array->getElementValue(accept(expression->index_expression)->toInt()));
    case Type::BOOLEAN_ARRAY:
      return std::make_shared<Boolean>(array->getElementValue(accept(expression->index_expression)->toInt()));
    default:
      throw std::runtime_error("Unexpected array type: " + toString(array->getType()));
  }
}
