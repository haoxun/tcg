
%skeleton "lalr1.cc"
%require "3.0.2"

%defines     "generated_parser.h"
%output      "generated_parser.cc"
%name-prefix "clidoc"

%define parser_class_name {BisonGeneratedParser}
%define api.token.constructor
%define api.value.type variant

// code inserted in header.
%code requires {


// Forward declarations.
namespace clidoc {

class FlexGeneratedScanner;

}  // namespace clidoc

}  // %code requires

// code inserted in implementation.
%code {

#include <stdexcept>

#include "src/generated_scanner.h"
#include "src/generated_parser.h"

#undef yylex
#define yylex lexer_ptr->lex

// Error report function.
void clidoc::BisonGeneratedParser::error(const std::string &msg) {
  throw std::logic_error("clidoc::BisonGeneratedParser::error");
}

}  // %code

%parse-param { clidoc::FlexGeneratedScanner *lexer_ptr }
%parse-param { clidoc::Doc::SharedPtr *doc_node_ptr }
%parse-param { clidoc::OptionBindingRecorder *recorder_ptr }

// Terminal with value.
%token <std::string>
	K_BEGIN
	K_END
	K_INPUT
	K_OUTPUT

	K_BOOLEAN_TRUE
	K_BOOLEAN_FALSE

	K_EQUAL_SIGN
	K_COMMA
	K_COLON
	K_L_BRACKET
	K_R_BRACKET
	K_L_BRACE
	K_R_BRACE
;

// Terminal without value.
%token
  ID
  SHORT_STRING
  LONG_STRING
  DECIMAL_INTEGER
  FLOAT_NUMBER
;

// non-terminal nodes.
%type <WeakPtr> testcases;
%type <WeakPtr> single_testcase;
%type <WeakPtr> body;
%type <WeakPtr> compound;
%type <WeakPtr> list;
%type <WeakPtr> dict;
%type <WeakPtr> pairs;
%type <WeakPtr> single_pair;
%type <WeakPtr> elements;
%type <WeakPtr> single_element;
%type <WeakPtr> boolean;
%type <WeakPtr> number;
%type <WeakPtr> string;

%%

// testcases : testcases single_testcase
//           | single_testcase
testcases : testcases single_testcase {
}
          | single_testcase {
}

// single_testcase : K_BEGIN ID body K_END
single_testcase : K_BEGIN ID body K_END {
}

// body : K_INPUT K_EQUAL_SIGN compound K_OUTPUT K_EQUAL_SIGN compound
body : K_INPUT K_EQUAL_SIGN compound K_OUTPUT K_EQUAL_SIGN compound {
}

// compound : single_element
//          | list
//          | dict
compound : single_element {
}
         | list {
}
         | dict {
}

// list : K_L_BRACKET elements K_R_BRACKET
list : K_L_BRACKET elements K_R_BRACKET {
}

// elements : single_element K_COMMA elements
//          | single_element K_COMMA
//          | single_element
elements : single_element K_COMMA elements {
}
         | single_element K_COMMA {
}
         | single_element {
}

// dict : K_L_BRACE pairs K_R_BRACE
dict : K_L_BRACE pairs K_R_BRACE {
}

// pairs : single_pair K_COMMA pairs
//       | single_pair K_COMMA
//       | single_pair
pairs : single_pair K_COMMA pairs {
}
      | single_pair K_COMMA {
}
      | single_pair {
}

// single_pair : single_element K_COLON single_element
single_pair : single_element K_COLON single_element {
}

// single_element : boolean
//                | number
//                | string
single_element : boolean {
}
               | number {
}
               | string {
}

// boolean : K_BOOLEAN_TRUE
//         | K_BOOLEAN_FALSE
boolean : K_BOOLEAN_TRUE {
}
        | K_BOOLEAN_FALSE {
}

// number : DECIMAL_INTEGER
//        | FLOAT_NUMBER
number : DECIMAL_INTEGER {
}
       | FLOAT_NUMBER {
}

// string : SHORT_STRING
//        | LONG_STRING
string : SHORT_STRING {
}
       | LONG_STRING {
}

%%
