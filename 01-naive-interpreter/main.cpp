#include <iostream>
#include <string>

#include <driver.hh>

int main(int argc, char** argv) {
  int result = 0;
  bool trace_parsing = false;
  bool trace_scanning = false;
  std::string input;

  for (int i = 1; i < argc; ++i) {
    if (argv[i] == std::string("-p")) {
      trace_parsing = true;
    } else if (argv[i] == std::string("-s")) {
      trace_scanning = true;
    } else {
      input = argv[i];
      break;
    }
  }

  Driver driver(trace_parsing, trace_scanning);
  if (driver.Parse(input) != 0) {
    result = 1;
  }

  return result;
}