from __future__ import unicode_literals
from pytest import fixture
from tcg.ast.lexer import create_lexer
from tcg.ast.parser import create_parser
from tcg.ast.elements import (ID, LongString, ShortString, Float, Integer,
                              Boolean, List, Dict, TestCase)


@fixture
def parser():
    return create_parser()


def unpack_testcase(parser, doc):
    lexer = create_lexer()
    lexer.input(doc)
    testcases = parser.parse(lexer=lexer)

    assert len(testcases) == 1
    tc = testcases[0]
    return tc.id, tc.input_value, tc.output_value


def test_number(parser):
    doc = '''
begin test_id
input: 42
output: -0.1
end'''
    _, input_value, output_value = unpack_testcase(parser, doc)
    assert Integer(42) == input_value
    assert Float(-0.1) == output_value


def test_string(parser):
    doc = '''
begin test_id
input: "short"
output:
"""
long
"""
end'''
    _, input_value, output_value = unpack_testcase(parser, doc)
    assert ShortString('short') == input_value
    assert LongString('long') == output_value


def test_list(parser):
    doc = '''
begin test_id
input: [1, 2, 3]
output: [1.0, "string",]
end'''
    id, input_value, output_value = unpack_testcase(parser, doc)
    assert id == ID('test_id')
    assert List([Integer(1), Integer(2), Integer(3)]) == input_value
    assert List([Float(1.0), ShortString('string')]) == output_value


def test_dict(parser):
    doc = '''
begin test_id
input: {1: "test 1", 2: "test 2"}
output: {0.1: 1, 1:2}
end'''
    _, input_value, output_value = unpack_testcase(parser, doc)
    assert Dict({Integer(1): ShortString('test 1'),
                 Integer(2): ShortString('test 2')}) == input_value
    assert Dict({Float(0.1): Integer(1),
                 Integer(1): Integer(2)}) == output_value


def test_nested_list(parser):
    doc = '''
begin test_id
input = [1, [2, 3]]
output = [1, {1: 2}]
end'''
    _, input_value, output_value = unpack_testcase(parser, doc)
    assert List([Integer(1),
                 List([Integer(2), Integer(3)])]) == input_value
    assert List([Integer(1),
                 Dict({Integer(1): Integer(2)})]) == output_value


def test_nested_dict(parser):
    doc = '''
begin test_id
input = {1: {1: 2}}
output = {1: [2, 3]}
end'''
    _, input_value, output_value = unpack_testcase(parser, doc)
    assert Dict({Integer(1): Dict({Integer(1): Integer(2)})}) == input_value
    assert Dict({Integer(1): List([Integer(2), Integer(3)])}) == output_value
