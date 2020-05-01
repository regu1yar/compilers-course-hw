%skeleton "lalr1.cc"
%require "3.5"

%defines // defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include <iostream>
    #include <exception>

    class Scanner;
    class Driver;
}

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "runtime_error.h"
    #include "compilation_error.h"
    #include "exceptions.h"
    #include "location.hh"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    ASSIGN "="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    PERCENT "%"
    AND "&&"
    OR "||"
    EXCL "!"
    LESS "<"
    GREATER ">"
    EQUALS "=="
    LPAREN "("
    RPAREN ")"
    LBRACKET "["
    RBRACKET "]"
    LBRACE "{"
    RBRACE "}"
    DASH ";"
    DOT "."
    COMMA ","
    INT_TYPE "int"
    BOOLEAN_TYPE "boolean"
    IF "if"
    ELSE "else"
    WHILE "while"
    ASSERT "assert"
    CLASS_DECL "class"
    PUBLIC_MOD "public"
    PRIVATE_MOD "private"
    PROTECTED_MOD "protected"
    RETURN "return"
    THIS "this"
    STATIC "static"
    VOID "void"
    MAIN "main"
    SOUT "System.out.println"
    NEW "new"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> INT_VALUE "int_value"
%token <bool> TRUE "true"
%token <bool> FALSE "false"

%nterm <int> int_expr
%nterm <bool> boolean_expr
%nterm <bool> boolean_value

%printer { yyo << $$; } <*>;

%%

%start program;
program: main_class { };

main_class: "class" "identifier" "{" "public" "static" "void" "main" "(" ")" "{" statements "}" "}"  { };

statements:
	%empty {}
	| statement statements {};

statement:
	"assert" "(" int_expr ")" ";" {
		if (!$3) {
			driver.initRuntimeError(RuntimeError(
				driver.getParserLocation().begin.line,
				driver.getParserLocation().begin.column,
				"Assert"
			));
		}
	}
	| "assert" "(" boolean_expr ")" ";" {
    if (!$3) {
      driver.initRuntimeError(RuntimeError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        "Assert"
      ));
    }
  }
	| local_variable_declaration {}
	| "System.out.println" "(" int_expr ")" ";"  { std::cout << $3 << std::endl; }
	| "System.out.println" "(" boolean_expr ")" ";"  {
		if ($3) {
			std::cout << "true" << std::endl;
		} else {
			std::cout << "false" << std::endl;
		}
	}
	| "identifier" "=" int_expr ";" {
		try {
			driver.setIntVariableValue($1, $3);
		} catch (const std::exception& e) {
			driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
		}
	}
	| "identifier" "=" boolean_expr ";" {
    try {
      driver.setBooleanVariableValue($1, $3);
    } catch (const std::exception& e) {
      driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
    }
  }
  | "identifier" "[" int_expr "]" "=" int_expr ";" {
		try {
      driver.setIntArrayElementValue($1, $3, $6);
    } catch (const std::exception& e) {
      driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
    }
  }
  | "identifier" "[" int_expr "]" "=" boolean_expr ";" {
		try {
      driver.setBooleanArrayElementValue($1, $3, $6);
    } catch (const std::exception& e) {
      driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
    }
  }
  | "identifier" "=" "new" "int" "[" int_expr "]" ";" {
    try {
      driver.allocateMemoryForIntArray($1, $6);
    } catch (const std::exception& e) {
      driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
    }
  }
  | "identifier" "=" "new" "boolean" "[" int_expr "]" ";" {
    try {
      driver.allocateMemoryForBooleanArray($1, $6);
    } catch (const std::exception& e) {
      driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
    }
  };

//expr:
//  <expr> "." length  |
//  new <type identifier> "(" ")"  |
//  this  |
//  <method invocation>

local_variable_declaration: variable_declaration {};

%left "||";
%left "&&";
%left NEGATION;
%left "<" "==" ">";
%left "+" "-";
%left "*" "/" "%";
%left UNMINUS;

int_expr:
	"int_value"
	| "identifier" {
		try {
      $$ = driver.getIntVariableValue($1);
    } catch (const std::exception& e) {
      driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
    }
	}
	| "identifier" "[" int_expr "]" {
		try {
      $$ = driver.getIntArrayElementValue($1, $3);
    } catch (const std::exception& e) {
      driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
    }
	}
	| int_expr "+" int_expr { $$ = $1 + $3; }
  | int_expr "-" int_expr { $$ = $1 - $3; }
  | int_expr "*" int_expr { $$ = $1 * $3; }
  | int_expr "/" int_expr { $$ = $1 / $3; }
  | int_expr "%" int_expr { $$ = $1 % $3; }
  | "-" int_expr %prec UNMINUS { $$ = - $2; }
  | "(" int_expr ")" { $$ = $2; };

boolean_expr:
	boolean_value { $$ = $1; }
	| "identifier" {
		try {
      $$ = driver.getBooleanVariableValue($1);
    } catch (const std::exception& e) {
      driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
    }
	}
	| "identifier" "[" int_expr "]" {
		try {
      $$ = driver.getBooleanArrayElementValue($1, $3);
    } catch (const std::exception& e) {
      driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
    }
	}
	| boolean_expr "&&" boolean_expr { $$ = $1 && $3; }
  | boolean_expr "||" boolean_expr { $$ = $1 || $3; }
  | "!" boolean_expr %prec NEGATION { $$ = !$2; }
  | int_expr "<" int_expr { $$ = $1 < $3; }
  | int_expr ">" int_expr { $$ = $1 > $3; }
  | int_expr "==" int_expr { $$ = $1 == $3; }
  | "(" boolean_expr ")" { $$ = $2; };

variable_declaration:
	"int" "identifier" ";" {
		try {
      driver.declareIntVariable($2);
    } catch (const std::exception& e) {
      driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
    }
	}
	| "boolean" "identifier" ";" {
    try {
      driver.declareBooleanVariable($2);
    } catch (const std::exception& e) {
      driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
    }
  }
  | "int" "[" "]" "identifier" ";" {
    try {
      driver.declareIntArray($4);
    } catch (const std::exception& e) {
      driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
    }
  }
  | "boolean" "[" "]" "identifier" ";" {
    try {
      driver.declareBooleanArray($4);
    } catch (const std::exception& e) {
      driver.addCompilationError(CompilationError(
        driver.getParserLocation().begin.line,
        driver.getParserLocation().begin.column,
        e.what()
      ));
    }
  };

boolean_value: "true" | "false";

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << "Syntax error at " << l << ": " << m << '\n';
}
