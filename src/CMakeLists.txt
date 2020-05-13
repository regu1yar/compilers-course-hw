project(mini-java-compiler)

set(
  SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/driver.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/main_class.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/program.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statement_list.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/assert_statement.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/assignment_statement.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/condition_clause_statement.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/print_statement.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/scope_statement.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/variable_declaration_statement.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/while_cycle_statement.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/int_value_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/boolean_value_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/identifier_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/array_element_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/plus_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/minus_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/star_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/slash_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/percent_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/unary_minus_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/parentheses_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/and_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/or_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/negation_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/less_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/greater_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/equals_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/length_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/int_array_allocation_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/boolean_array_allocation_expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/variable_declarations/int_variable_declaration.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/variable_declarations/boolean_variable_declaration.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/variable_declarations/int_array_declaration.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/variable_declarations/boolean_array_declaration.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/condition_clauses/if_clause.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/condition_clauses/if_else_clause.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/assignments/variable_assignment.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/assignments/array_element_assignment.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/visitors/interpreter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/types/int.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/types/boolean.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/symbol_table/scope_layer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/visitors/symbol_tree_visitor.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/visitors/visitor.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/types/basic_type.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/variable_declarations/variable_declaration.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/statement.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/expression.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/condition_clauses/condition_clause.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/assignments/assignment.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/base_treee_element.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/visitors/type_check_visitor.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/visitors/template_visitor.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/visitors/print_visitor.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/empty_statement.cpp
)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(
  MyParser
  parser.y
  ${CMAKE_CURRENT_SOURCE_DIR}/parser.cpp
  COMPILE_FLAGS --graph
  DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
  MyScanner
  scanner.l
  ${CMAKE_CURRENT_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
  mini-java-compiler
  main.cpp
  ${SOURCES}
  ${BISON_MyParser_OUTPUTS}
  ${FLEX_MyScanner_OUTPUTS}
)

target_include_directories(mini-java-compiler
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/interpreter_errors
  ${CMAKE_CURRENT_SOURCE_DIR}/exceptions
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/assignments
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/variable_declarations
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/condition_clauses
  ${CMAKE_CURRENT_SOURCE_DIR}/visitors
  ${CMAKE_CURRENT_SOURCE_DIR}/types
  ${CMAKE_CURRENT_SOURCE_DIR}/symbol_table
)

add_custom_target(
  VisitorTree
  COMMAND dot -Tpng ${mini-java-compiler_SOURCE_DIR}/parser.gv -o ${mini-java-compiler_SOURCE_DIR}/parser.png

  DEPENDS ${mini-java-compiler_SOURCE_DIR}/parser.cpp
)

add_dependencies(mini-java-compiler VisitorTree)
