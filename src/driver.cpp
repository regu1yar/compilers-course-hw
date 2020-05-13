#include <iostream>

#include "driver.hh"
#include "parser.hh"


Driver::Driver(bool trace_parsing, bool trace_scanning)
    : trace_parsing_(trace_parsing)
    , trace_scanning_(trace_scanning)
    , scanner_(*this)
    , parser_(scanner_, *this)
{ }

int Driver::Parse(const std::string& f) {
  file_ = f;
  location_.initialize(&file_);
  ScanBegin();
  parser_.set_debug_level(trace_parsing_);
  int res = parser_();
  ScanEnd();
  return res;
}

void Driver::ScanBegin() {
  scanner_.set_debug(trace_scanning_);
  if (file_.empty() || file_ == "-") {
  } else {
    stream_.open(file_);
    std::cout << file_ << std::endl;
    scanner_.yyrestart(&stream_);
  }
}

void Driver::ScanEnd() {
  stream_.close();
}

const yy::location &Driver::getParserLocation() const {
  return location_;
}

yy::location Driver::getParserLocation() {
  return location_;
}

void Driver::buildSymbolTree() {
  global_layer_ = SymbolTreeVisitor().buildSymbolTree(program_);
}

void Driver::runTypeCheck() {
  auto errors = TypeCheckVisitor(global_layer_).runCheck(program_);
  for(const auto& error : errors) {
    std::cerr << error.toString() << std::endl;
  }
}

void Driver::interpret() {
  Interpreter(global_layer_).run(program_);
}

void Driver::setProgram(Program* program) {
  program_ = program;
}

Driver::~Driver() {
  delete program_;
  delete global_layer_;
}

void Driver::printAST() const {
  PrintVisitor("ast.txt").printAST(program_);
}
