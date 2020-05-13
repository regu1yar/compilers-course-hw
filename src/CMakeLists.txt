project(mini-java-compiler)

set(
  HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/driver.hh
  ${CMAKE_CURRENT_SOURCE_DIR}/interpreter_errors/runtime_error.h
  ${CMAKE_CURRENT_SOURCE_DIR}/interpreter_errors/compilation_error.h
  ${CMAKE_CURRENT_SOURCE_DIR}/interpreter_errors/error.h
  ${CMAKE_CURRENT_SOURCE_DIR}/parser.hh
  ${CMAKE_CURRENT_SOURCE_DIR}/exceptions.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/main_class.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/program.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statement_list.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/statement.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/expression.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/variable_declarations/variable_declaration.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/assignments/assignment.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/assert_statement.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/assignment_statement.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/condition_clause_statement.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/print_statement.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/scope_statement.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/variable_declaration_statement.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/while_cycle_statement.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/int_value_expression.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/boolean_value_expression.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/identifier_expression.h
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/array_element_expression.h
)

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
  grammar/expressions/plus_expression.cpp grammar/expressions/plus_expression.h grammar/expressions/minus_expression.cpp grammar/expressions/minus_expression.h grammar/expressions/star_expression.cpp grammar/expressions/star_expression.h grammar/expressions/slash_expression.cpp grammar/expressions/slash_expression.h grammar/expressions/percent_expression.cpp grammar/expressions/percent_expression.h grammar/expressions/unary_minus_expression.cpp grammar/expressions/unary_minus_expression.h grammar/expressions/parentheses_expression.cpp grammar/expressions/parentheses_expression.h grammar/expressions/and_expression.cpp grammar/expressions/and_expression.h grammar/expressions/or_expression.cpp grammar/expressions/or_expression.h grammar/expressions/negation_expression.cpp grammar/expressions/negation_expression.h grammar/expressions/less_expression.cpp grammar/expressions/less_expression.h grammar/expressions/greater_expression.cpp grammar/expressions/greater_expression.h grammar/expressions/equals_expression.cpp grammar/expressions/equals_expression.h grammar/expressions/length_expression.cpp grammar/expressions/length_expression.h grammar/expressions/int_array_allocation_expression.cpp grammar/expressions/int_array_allocation_expression.h grammar/expressions/boolean_array_allocation_expression.cpp grammar/expressions/boolean_array_allocation_expression.h grammar/variable_declarations/int_variable_declaration.cpp grammar/variable_declarations/int_variable_declaration.h grammar/variable_declarations/boolean_variable_declaration.cpp grammar/variable_declarations/boolean_variable_declaration.h grammar/variable_declarations/int_array_declaration.cpp grammar/variable_declarations/int_array_declaration.h grammar/variable_declarations/boolean_array_declaration.cpp grammar/variable_declarations/boolean_array_declaration.h grammar/condition_clauses/if_clause.cpp grammar/condition_clauses/if_clause.h grammar/condition_clauses/if_else_clause.cpp grammar/condition_clauses/if_else_clause.h grammar/assignments/variable_assignment.cpp grammar/assignments/variable_assignment.h grammar/assignments/array_element_assignment.cpp grammar/assignments/array_element_assignment.h visitors/interpreter.cpp visitors/interpreter.h types/int.cpp types/int.h types/boolean.cpp types/boolean.h symbol_table/scope_layer.cpp symbol_table/scope_layer.h visitors/symbol_tree_visitor.cpp visitors/symbol_tree_visitor.h types/array.h visitors/visitor.cpp types/basic_type.cpp grammar/variable_declarations/variable_declaration.cpp grammar/statements/statement.cpp grammar/expressions/expression.cpp grammar/condition_clauses/condition_clause.cpp grammar/assignments/assignment.cpp grammar/base_treee_element.cpp visitors/type_check_visitor.cpp visitors/type_check_visitor.h visitors/template_visitor.cpp visitors/template_visitor.h visitors/print_visitor.cpp visitors/print_visitor.h)

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
