
from pytest import fixture
from tcg.ast.parser import create_parser


@fixture
def parser():
    return create_parser()


def test_simple(parser):
    pass
