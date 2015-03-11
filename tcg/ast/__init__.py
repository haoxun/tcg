from __future__ import absolute_import, division, print_function

import os
from io import open

from .lexer import create_lexer
from .parser import create_parser


def parse_file(rel_path):
    doc = open(os.path.abspath(rel_path), encoding='utf-8').read()
    lexer = create_lexer()
    parser = create_parser()
    lexer.input(doc)
    return parser.parse(lexer=lexer)
