%{
// Use parser defined tokens.
#include "src/generated_scanner.h"
#include "src/generated_parser.h"

#define YY_DECL                             \
  clidoc::BisonGeneratedParser::symbol_type \
  clidoc::FlexGeneratedScanner::lex()
%}

%option c++
%option noyywrap nounput batch debug noinput
%option outfile="generated_scanner.cc"

DIGIT			           [0-9]
ALPHABET			       [a-zA-Z_]
NON_SPACE            [^ \t\r\n\v\f]
DOUBLE_QUOTE         \"
TRIBAL_QUOTE         \"\"\"

K_BEGIN              (?i:begin)
K_END                (?i:end)
K_INPUT              (?i:input)
K_OUTPUT             (?i:output)

K_BOOLEAN_TRUE       "true"
K_BOOLEAN_FALSE      "false"

K_EQUAL_SIGN         "="
K_COMMA              ","
K_COLON              ":"
K_L_BRACKET          "["
K_R_BRACKET          "]"
K_L_BRACE            "{"
K_R_BRACE            "}"

ID                   {ALPHABET}({ALPHABET}|{DIGIT})*

SHORT_STRING_CHAR    [^"\n\\]
LONG_STRING_CHAR     [^\\]
ESCAPE_SEQ           \\.
SHORT_STRING         {DOUBLE_QUOTE}({SHORT_STRING_CHAR}|{ESCAPE_SEQ})*{DOUBLE_QUOTE}
LONG_STRING          {TRIBAL_QUOTE}({LONG_STRING_CHAR}|{ESCAPE_SEQ})*{TRIBAL_QUOTE}

NON_ZERO_DIGIT       [1-9]
DECIMAL_INTEGER      ({NON_ZERO_DIGIT}{DIGIT}*)|"0"
FLOAT_NUMBER         {DIGIT}+"."{DIGIT}+

%%

<<EOF>>              return clidoc::BisonGeneratedParser::make_END();

%%
// Bug fix.
int yyFlexLexer::yylex() { return 1; }
