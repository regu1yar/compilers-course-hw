project(naive-interpreter)
set(
  HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/driver.hh
  interpreter_errors/runtime_error.h
  ${ParserExample_SOURCE_DIR}/parser.hh
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
  ${ParserExample_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
  naive-interpreter
  main.cpp
  driver.cpp
  ${BISON_MyParser_OUTPUTS}
  ${FLEX_MyScanner_OUTPUTS}
)
target_include_directories(naive-interpreter
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/interpreter_errors
  ${CMAKE_CURRENT_SOURCE_DIR}/exceptions
)
