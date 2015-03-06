
from ply.lex import TOKEN, lex

__all__ = ['create_lexer']

keyworks = {'BEGIN', 'END', 'INPUT', 'OUTPUT'}

tokens = [
    # with value.
    'ID',
    'SHORT_STRING',
    'LONG_STRING',
    'DECIMAL_INTEGER',
    'FLOAT_NUMBER',
    # without value.
    'BOOLEAN_TRUE',
    'BOOLEAN_FALSE',
    'EQUAL_SIGN',
    'COMMA',
    'COLON',
    'L_BRACKET',
    'R_BRACKET',
    'L_BRACE',
    'R_BRACE',
    # special.
    'COMMENT',
    'WHITESPACE',
]

tokens = tokens + list(keyworks)

# basic elements.
DIGIT = r'[0-9]'
NON_ZERO_DIGIT = r'[1-9]'
ALPHABET = r'[a-zA-Z_]'
NON_SPACE = r'\S'
DOUBLE_QUOTE = r'"'
TRIBAL_DOUBLE_QUOTE = r'"""'
SHORT_STRING_CHAR = r'[^"\n\\]'
LONG_STRING_CHAR = r'[^\\]'
ESCAPE_SEQ = r'\\.'

# token with value.
r_ID = r'{0}({0}|{1})*'.format(
    ALPHABET, DIGIT,
)
r_SHORT_STRING = r'{0}({1}|{2})*{0}'.format(
    DOUBLE_QUOTE, SHORT_STRING_CHAR, ESCAPE_SEQ,
)
r_LONG_STRING = r'{0}({1}|{2})*{0}'.format(
    TRIBAL_DOUBLE_QUOTE, LONG_STRING_CHAR, ESCAPE_SEQ,
)
r_DECIMAL_INTEGER = r'({0}{1}*)|"0"'.format(
    NON_ZERO_DIGIT, DIGIT,
)
r_FLOAT_NUMBER = r'{0}+"."{0}+'.format(
    DIGIT,
)


@TOKEN(r_ID)
def t_ID(t):
    keyword_value = t.value.upper()
    t.type = keyword_value if keyword_value in keyworks else 'ID'
    return t


@TOKEN(r_LONG_STRING)
def t_LONG_STRING(t):
    # remove TRIBAL_DOUBLE_QUOTE.
    chars = list(t.value[3:-3])
    # remove leading and tailing newline character.
    NEWLINE = '\n'
    if chars[0] == NEWLINE:
        chars.pop(0)
    if chars[-1] == NEWLINE:
        chars.pop()
    t.value = ''.join(chars)
    return t


@TOKEN(r_SHORT_STRING)
def t_SHORT_STRING(t):
    # remove DOUBLE_QUOTE.
    t.value = t.value[1:-1]
    return t


@TOKEN(r_DECIMAL_INTEGER)
def t_DECIMAL_INTEGER(t):
    t.value = int(t.value)
    return t


@TOKEN(r_FLOAT_NUMBER)
def r_FLOAT_NUMBER(t):
    t.value = float(t.value)
    return t


# token without value.
t_BOOLEAN_TRUE = r'true'
t_BOOLEAN_FALSE = r'false'
t_EQUAL_SIGN = r'='
t_COMMA = r','
t_COLON = r':'
t_L_BRACKET = r'\['
t_R_BRACKET = r'\]'
t_L_BRACE = r'\{'
t_R_BRACE = r'\}'

t_ignore_COMMENT = r'\#.*'
t_ignore_WHITESPACE = r'\s'


# misc configurations.
def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)


def t_error(t):
    print "Illegal character '%s'" % t.value[0]
    t.lexer.skip(1)


def create_lexer():
    return lex()
