from __future__ import absolute_import, division, print_function

from tcg.ast import parse_file
from tcg.ast.elements import (ID, LongString, ShortString, Float, Integer,
                              Boolean, List, Dict, TestCase)


def test_parse_file(tmpdir):
    doc = '''
begin test_id
input: [1, 2, 3]
output: 42
end'''
    tmp_file = tmpdir.join('testfile')
    tmp_file.write(doc)
    file_path = str(tmp_file)

    testcases = parse_file(file_path)
    assert len(testcases) == 1
    testcase = testcases[0]
    assert ID('test_id') == testcase.id
    assert List([Integer(1), Integer(2), Integer(3)]) == testcase.input_value
    assert Integer(42) == testcase.output_value
