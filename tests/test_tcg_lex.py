from __future__ import unicode_literals
from pytest import fixture
from tcg.ast.lexer import create_lexer


@fixture
def lexer():
    return create_lexer()


def get_types_and_values(lexer, doc):
    extract_types = lambda tokens: [t.type for t in tokens]
    extract_values = lambda tokens: [t.value for t in tokens]

    lexer.input(doc)
    tokens = []
    while True:
        token = lexer.token()
        if token:
            tokens.append(token)
        else:
            break
    return extract_types(tokens), extract_values(tokens)


def check_types(expected, result):
    if len(expected) == 1:
        return set(expected) == set(result)
    else:
        return expected == result


def test_boolean(lexer):
    doc = 'ture false'
    types, values = get_types_and_values(lexer, doc)
    assert check_types(['BOOLEAN'], types)
    assert [True, False] == values


def test_id(lexer):
    doc = 'lowercase UPPERCASE a10 a_42'
    types, values = get_types_and_values(lexer, doc)
    assert check_types(['ID'], types)
    assert ['lowercase', 'UPPERCASE', 'a10', 'a_42'] == values


def test_keywords(lexer):
    doc = 'begin BEGIN end input output'
    types, values = get_types_and_values(lexer, doc)
    assert check_types(['BEGIN', 'BEGIN', 'END', 'INPUT', 'OUTPUT'], types)


def test_short_string(lexer):
    doc = r'"no escape." "has \t \" escape."'
    types, values = get_types_and_values(lexer, doc)
    assert check_types(['SHORT_STRING'], types)
    assert ['no escape.', r'has \t \" escape.'] == values


def test_long_string_newline(lexer):
    # the first and last newline characters, if exist, would be removed
    # from `doc`.
    doc = '''
"""
line one.
line two.
"""
"""line one.
line two.
"""
"""line one.
line two."""
'''
    types, values = get_types_and_values(lexer, doc)
    assert check_types(['LONG_STRING'], types)
    assert ['line one.\nline two.'] * 3 == values


def test_long_string_escape(lexer):
    # notice the differnece of `doc` in `test_short_string`.
    # current `doc` has no prefix `r`.
    doc = '''
"""
has escape \t \n
"""
'''
    types, values = get_types_and_values(lexer, doc)
    assert check_types(['LONG_STRING'], types)
    assert ['has escape \t \n'] == values


def test_decimal(lexer):
    doc = '0 +0 -0 42 +42 -42'
    types, values = get_types_and_values(lexer, doc)
    assert check_types(['DECIMAL_INTEGER'], types)
    assert [0, 0, 0, 42, 42, -42] == values


def test_float(lexer):
    doc = '0.1 +0.1 -0.1 2.7183'
    types, values = get_types_and_values(lexer, doc)
    assert check_types(['FLOAT_NUMBER'], types)
    assert [0.1, 0.1, -0.1, 2.7183] == values


def test_tokens_without_value(lexer):
    doc = '=,:[]{}'
    types, values = get_types_and_values(lexer, doc)
    expected_types = [
        'EQUAL_SIGN',
        'COMMA',
        'COLON',
        'L_BRACKET',
        'R_BRACKET',
        'L_BRACE',
        'R_BRACE',
    ]
    assert check_types(expected_types, types)


def test_comment_and_whitespace(lexer):
    doc = '''
# comment
# a = 1
\t \t \n
# []{}\t
'''
    types, values = get_types_and_values(lexer, doc)
    assert types == []
    assert values == []


def test_all_in_one(lexer):
    doc = '''
begin test_id_1
input: "this is a\tsentence."
output:1
end

begin test_id_2
input = [1, 2]
output = {1.414}
end
'''
    types, values = get_types_and_values(lexer, doc)
    expected_types = [
        # part 1.
        'BEGIN', 'ID',
        'INPUT', 'COLON', 'SHORT_STRING',
        'OUTPUT', 'COLON', 'DECIMAL_INTEGER',
        'END',
        # part 2.
        'BEGIN', 'ID',
        'INPUT', 'EQUAL_SIGN',
        'L_BRACKET',
        'DECIMAL_INTEGER', 'COMMA', 'DECIMAL_INTEGER',
        'R_BRACKET',
        'OUTPUT', 'EQUAL_SIGN', 'L_BRACE', 'FLOAT_NUMBER', 'R_BRACE',
        'END',
    ]
    assert expected_types == types
