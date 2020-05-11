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

    #include "forward_decl.h"
}

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "elements.h"

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
program: main_class { $$ = new Program($1); };

main_class: "class" "identifier" "{" "public" "static" "void" "main" "(" ")" "{" statements "}" "}"  {
	$$ = new MainClass($2, $11);
};

statements:
	%empty { $$ = new StatementList(); }
	| statements statement {
		$1->pushBack($2);
		$$ = $1;
	};

statement:
	"assert" "(" expr ")" ";" { $$ = new AssertStatement($3, driver.getParserLocation()); }
	| variable_declaration { $$ = new VariableDeclarationStatement($1); }
	| "{" statements "}" { $$ = new ScopeStatement($2); }
	| condition_clause { $$ = new ConditionClauseStatement($1); }
	| "while" "(" expr ")" statement { $$ = new WhileCycleStatement($3, $5); }
	| "System.out.println" "(" expr ")" ";"  { $$ = new PrintStatement($3); }
  | assignment { $$ = new AssignmentStatement($1); };
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
	"int_value" { $$ = new IntValueExpression($1, driver.getParserLocation()); }
	| boolean_value { $$ = new BooleanValueExpression($1, driver.getParserLocation()); }
	| "identifier" { $$ = new IdentifierExpression($1, driver.getParserLocation()); }
	| "identifier" "[" expr "]" { $$ = new ArrayElementExpression($1, $3, driver.getParserLocation()); }
	| expr "+" expr { $$ = new PlusExpression($1, $3, driver.getParserLocation()); }
  | expr "-" expr { $$ = new MinusExpression($1, $3, driver.getParserLocation()); }
  | expr "*" expr { $$ = new StarExpression($1, $3, driver.getParserLocation()); }
  | expr "/" expr { $$ = new SlashExpression($1, $3, driver.getParserLocation()); }
  | expr "%" expr { $$ = new PercentExpression($1, $3, driver.getParserLocation()); }
  | "-" expr %prec UNMINUS { $$ = new UnaryMinusExpression($2, driver.getParserLocation()); }
  | "(" expr ")" { $$ = new ParenthesesExpression($2); }
  | expr "&&" expr { $$ = new AndExpression($1, $3, driver.getParserLocation()); }
  | expr "||" expr { $$ = new OrExpression($1, $3, driver.getParserLocation()); }
  | "!" expr %prec NEGATION { $$ = new NegationExpression($2, driver.getParserLocation()); }
  | expr "<" expr { $$ = new LessExpression($1, $3, driver.getParserLocation()); }
  | expr ">" expr { $$ = new GreaterExpression($1, $3, driver.getParserLocation()); }
  | expr "==" expr { $$ = new EqualsExpression($1, $3, driver.getParserLocation()); }
  | expr "." "length" { $$ = new LengthExpression($1, driver.getParserLocation()); }
  | "new" "int" "[" expr "]" ";" { $$ = new IntArrayAllocationExpression($4, driver.getParserLocation()); }
  | "new" "boolean" "[" expr "]" ";" { $$ = new BooleanArrayAllocationExpression($4, driver.getParserLocation()); };
//  | new "identifier" "(" ")" { }
//	| "this" { }
//  | method_invocation { };

variable_declaration:
	"int" "identifier" ";" { $$ = new IntVariableDeclaration($2, driver.getParserLocation()); }
	| "boolean" "identifier" ";" { $$ = new BooleanVariableDeclaration($2, driver.getParserLocation()); }
  | "int" "[" "]" "identifier" ";" { $$ = new IntArrayDeclaration($4, driver.getParserLocation()); }
  | "boolean" "[" "]" "identifier" ";" { $$ = new BooleanArrayDeclaration($4, driver.getParserLocation()); };

condition_clause:
	"if" "(" expr ")" statement { $$ = new IfClause($3, $5); }
	| "if" "(" expr ")" statement "else" statement { $$ = new IfElseClause($3, $5, $7); }

assignment:
	"identifier" "=" expr ";" { $$ = new VariableAssignment($1, $3); }
  | "identifier" "[" expr "]" "=" expr ";" { $$ = new ArrayElementAssignment($1, $3, $6); };

boolean_value: "true" | "false";

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << "Syntax error at " << l << ": " << m << '\n';
}
