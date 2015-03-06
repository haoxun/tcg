
from tcg.ast.lexer import create_lexer

def test_simple():
    lexer = create_lexer()
    data = '''
begin test_id
inoput =
"""
line one
line two
"""
output = 2
end'''
    lexer.input(data)
    while True:
        t = lexer.token()
        if not t: break
        print t
    assert False

