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
    LENGTH "length"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> INT_VALUE "int_value"
%token <bool> TRUE "true"
%token <bool> FALSE "false"

%nterm <bool> boolean_value

%nterm <Program*> program
%nterm <MainClass*> main_class
%nterm <StatementList*> statements
%nterm <Statement*> statement
%nterm <Expression*> expr
%nterm <VariableDeclaration*> variable_declaration
%nterm <Assignment*> assignment
%nterm <ConditionClause*> condition_clause

%%

%start program;
program: main_class { };

main_class: "class" "identifier" "{" "public" "static" "void" "main" "(" ")" "{" statements "}" "}"  { };

statements:
	%empty { }
	| statements statement { };

statement:
	"assert" "(" expr ")" ";" { }
	| variable_declaration { }
	| "{" statements "}" { }
	| condition_clause { }
	| "while" "(" expr ")" statement
	| "System.out.println" "(" expr ")" ";"  { }
  | assignment { };
//	| "return" expr ";" { }
//	| method_invocation ";" { };

%left "||";
%left "&&";
%left NEGATION;
%left "<" "==" ">";
%left "+" "-";
%left "*" "/" "%";
%left UNMINUS;

expr:
	"int_value" { }
	| boolean_value { }
	| "identifier" { }
	| "identifier" "[" expr "]" { }
	| expr "+" expr { }
  | expr "-" expr { }
  | expr "*" expr { }
  | expr "/" expr { }
  | expr "%" expr { }
  | "-" expr %prec UNMINUS { }
  | "(" expr ")" { }
  | expr "&&" expr { }
  | expr "||" expr { }
  | "!" expr %prec NEGATION { }
  | expr "<" expr { }
  | expr ">" expr { }
  | expr "==" expr { }
  | expr "." "length" { }
  | "new" "int" "[" expr "]" ";" { };
  | "new" "boolean" "[" expr "]" ";" { };
//  | new "identifier" "(" ")" { }
//	| "this" { }
//  | method_invocation { };

variable_declaration:
	"int" "identifier" ";" { }
	| "boolean" "identifier" ";" { }
  | "int" "[" "]" "identifier" ";" { }
  | "boolean" "[" "]" "identifier" ";" { };

condition_clause:
	"if" "(" expr ")" statement { }
	| "if" "(" expr ")" statement "else" statement { }

assignment:
	"identifier" "=" expr ";" { }
  | "identifier" "[" expr "]" "=" expr ";" { };

boolean_value: "true" | "false";

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << "Syntax error at " << l << ": " << m << '\n';
}
