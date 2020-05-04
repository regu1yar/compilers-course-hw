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
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/expressions/expression_types.h
)

set(
  SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/driver.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/main_class.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/program.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statement_list.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/variable_declarations/variable_declaration.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/assignments/assignment.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/statements/assert_statement.cpp
)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(
  MyParser
  parser.y
  ${CMAKE_CURRENT_SOURCE_DIR}/parser.cpp
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
)
