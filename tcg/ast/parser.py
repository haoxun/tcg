from __future__ import unicode_literals
import os
from ply.yacc import yacc
from .lexer import tokens as lexer_tokens
from .elements import (ID, LongString, ShortString, Float, Integer, Boolean,
                       List, Dict, TestCase)


__all__ = ['create_parser']


tokens = lexer_tokens
start = 'testcases'


def p_testcases(p):
    '''testcases : testcases single_testcase
                 | empty'''
    if len(p) == 2:
        p[0] = []
    else:
        p[1].append(p[2])
        p[0] = p[1]


def p_single_testcase(p):
    'single_testcase : BEGIN ID body END'
    # build single_testcase.
    p[0] = TestCase(ID(p[2]), *p[3])


def p_body(p):
    'body : input_mark value output_mark value'
    p[0] = (p[2], p[4])


def p_input_mark(p):
    '''input_mark : INPUT COLON
                  | INPUT EQUAL_SIGN'''
    pass


def p_output_mark(p):
    '''output_mark : OUTPUT COLON
                   | OUTPUT EQUAL_SIGN'''
    pass


def p_value(p):
    '''value : single_value_element
             | compound'''
    p[0] = p[1]


def p_compound(p):
    '''compound : list
                | dict'''
    p[0] = p[1]


def p_list(p):
    '''list : L_BRACKET elements R_BRACKET
            | L_BRACKET R_BRACKET'''
    value = p[2] if len(p) == 4 else []
    p[0] = List(value)


def p_dict(p):
    '''dict : L_BRACE pairs R_BRACE
            | L_BRACE R_BRACE'''
    if len(p) == 3:
        p[0] = {}
        return
    generated_dict = dict()
    first_recorded = {}
    for key, value in p[2]:
        if key in generated_dict:
            if first_recorded[key]:
                generated_dict[key] = [generated_dict[key], value]
                first_recorded[key] = False
            else:
                generated_dict[key].append(value)
        else:
            generated_dict[key] = value
            first_recorded[key] = True

    p[0] = Dict(generated_dict)


def p_elements(p):
    '''elements : single_value_element COMMA elements
                | single_value_element COMMA
                | single_value_element'''
    if len(p) == 4:
        # non-leaf.
        p[3].insert(0, p[1])
        p[0] = p[3]
    else:
        # leaf.
        p[0] = [p[1]]


def p_pairs(p):
    '''pairs : single_pair COMMA pairs
             | single_pair COMMA
             | single_pair'''
    if len(p) == 4:
        # non-leaf.
        p[3].insert(0, p[1])
        p[0] = p[3]
    else:
        # leaf.
        p[0] = [p[1]]


def p_single_pair(p):
    'single_pair : single_key_element COLON single_value_element'
    p[0] = (p[1], p[3])


def p_single_key_element(p):
    '''single_key_element : boolean
                          | number
                          | string'''
    p[0] = p[1]


def p_single_value_element(p):
    '''single_value_element : single_key_element
                            | compound'''
    p[0] = p[1]


def p_boolean(p):
    'boolean : BOOLEAN'
    p[0] = Boolean(p[1])


def p_number(p):
    '''number : DECIMAL_INTEGER
              | FLOAT_NUMBER'''
    value = p[1]
    if isinstance(value, Integer.value_type):
        p[0] = Integer(value)
    else:
        p[0] = Float(value)


def p_short_string(p):
    'string : SHORT_STRING'
    p[0] = ShortString(p[1])


def p_long_string(p):
    'string : LONG_STRING'
    p[0] = LongString(p[1])


def p_empty(p):
    'empty :'
    pass


def p_error(p):
    pass


def create_parser():
    return yacc(
        debug=0,
        optimize=1,
        tabmodule='generated_parsetab',
        outputdir=os.path.dirname(__file__),
    )
