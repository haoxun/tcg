from __future__ import unicode_literals
import functools
from six import string_types, with_metaclass


class InitInjector(type):

    def __new__(cls, *args, **kwargs):
        generated_cls = type.__new__(cls, *args, **kwargs)

        def _init(self, value):
            value_type = getattr(generated_cls, 'value_type', None)
            if value_type is None or isinstance(value, value_type):
                self.value = value
            else:
                raise RuntimeError("InitInjector: wrong init type.")

        def _repr(self):
            return repr(self.value)

        def _eq(self, other):
            return type(self) == type(other) and self.value == other.value

        def _gt(self, other):
            return self.value > other.value

        def _hash(self):
            return hash(self.value)

        def inject_method(generated_cls, text, func):
            if text not in generated_cls.__dict__:
                setattr(generated_cls, text, func)

        inject_method(generated_cls, '__init__', _init)
        inject_method(generated_cls, '__repr__', _repr)
        inject_method(generated_cls, '__eq__', _eq)
        inject_method(generated_cls, '__gt__', _gt)
        inject_method(generated_cls, '__hash__', _hash)

        return functools.total_ordering(generated_cls)


class ID(with_metaclass(InitInjector)):
    value_type = string_types


class LongString(with_metaclass(InitInjector)):
    value_type = string_types


class ShortString(with_metaclass(InitInjector)):
    value_type = string_types


class Integer(with_metaclass(InitInjector)):
    value_type = int


class Float(with_metaclass(InitInjector)):
    value_type = float


class Boolean(with_metaclass(InitInjector)):
    value_type = bool


class List(with_metaclass(InitInjector)):
    value_type = list


class Dict(with_metaclass(InitInjector)):
    value_type = dict


class TestCase(object):
    def __init__(self, id, input_value, output_value):
        self.id = id
        self.input_value = input_value
        self.output_value = output_value

    def __repr__(self):
        template = (b'<ID: {0},'
                    b' Input: {1},'
                    b' Output: {2}>')
        return template.format(
            repr(self.id), repr(self.input_value), repr(self.output_value),
        )
