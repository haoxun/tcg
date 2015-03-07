
import six


class InitInjector(type):
    def __new__(cls, *args, **kwargs):
        generated_cls = type.__new__(cls, *args, **kwargs)

        # inject __init__.
        def init(self, value):
            value_type = getattr(generated_cls, '_value_type', None)
            if value_type is None or isinstance(value, value_type):
                self.value = value
            else:
                raise Exception("InitInjector: wrong type.")

        if '__init__' not in generated_cls.__dict__:
            generated_cls.__init__ = init
        return generated_cls


class ID(object):
    __metaclass__ = InitInjector
    _value_type = six.string_types


class LongString(object):
    __metaclass__ = InitInjector
    _value_type = six.string_types


class ShortString(object):
    __metaclass__ = InitInjector
    _value_type = six.string_types


class Integer(object):
    __metaclass__ = InitInjector
    _value_type = int


class Float(object):
    __metaclass__ = InitInjector
    _value_type = float


class Boolean(object):
    __metaclass__ = InitInjector
    _value_type = bool


class List(object):
    __metaclass__ = InitInjector
    _value_type = list


class Dict(object):
    __metaclass__ = InitInjector
    _value_type = dict


class TestCase(object):
    def __init__(self, id, input_value, output_value):
        self.id = id
        self.input_value = input_value
        self.output_value = output_value
