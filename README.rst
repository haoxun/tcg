What is ``tcg``
===============

``tcg`` stands for "TestCase Generator". With ``tcg``, you can write
testcases in a way that is **language independent**, and generate code
for specific language.

Syntax of ``tcg`` is simple:

::

    begin <test-id>
    input = <input value>
    output = <output value>
    end

where ``<test-id>`` defines the name/id of testcase, ``<input value>``
defines the input value, and ``<output value>`` defines expected output
value.

For example:

::

    begin TestToUpper1

    input = "foo"
    output = "FOO"

    end

    begin TestToUpper2

    input =
    """
    this is a raw string block,
    with multiple lines.
    """

    output =
    """
    THIS IS A RAW STRING BLOCK,
    WITH MULTIPLE LINES.
    """

    end

    begin test_split_word

    input = "a long long sentence."
    output = {"a", "long", "long", "sentence", "."}

    end

    begin test_map

    input = "a:1, b:2"
    output = {
      "a": 1,
      "b": 2,
    }

    end

By scanning previous testcases definition, ``tcg`` can generate code for
C++ googletest framework:

::

    // example.h
    namespace tcg {

    std::string TestToUpper1Input = "foo";
    std::string TestToUpper2Input =
        "this is a raw string block,\n"
        "with multiple lines.";
    ...
    void CheckTestToUpper1(const std::string &output) {
      std::string expected = "FOO";
      EXPECTED_EQ(expected, output);
    }
    void CheckTestToUpper2(const std::string &output) {
      std::string expected =
          "THIS IS A RAW STRING BLOCK,\n"
          "WITH MULTIPLE LINES.";
      EXPECTED_EQ("FOO", output);
    }

    }  // namespace tcg

Lexical Rules:

::

    DIGIT                      [0-9]
    ALPHABET                   [a-zA-Z_]
    NON_SPACE            [^ \t\r\n\v\f]
    DOUBLE_QUOTE         \"
    TRIBAL_QUOTE         \"\"\"

    K_BEGIN              (?i:begin)
    K_END                (?i:end)
    K_INPUT              (?i:input)
    K_OUTPUT             (?i:output)

    K_BOOLEAN_TRUE       "true"
    K_BOOLEAN_FALSE      "false"

    K_EQUAL_SIGN         "="
    K_COMMA              ","
    K_COLON              ":"
    K_L_BRACKET          "["
    K_R_BRACKET          "]"
    K_L_BRACE            "{"
    K_R_BRACE            "}"

    ID                   {ALPHABET}({ALPHABET}|{DIGIT})*

    SHORT_STRING_CHAR    [^"\n\\]
    LONG_STRING_CHAR     [^\\]
    ESCAPE_SEQ           \\.
    SHORT_STRING         {DOUBLE_QUOTE}({SHORT_STRING_CHAR}|{ESCAPE_SEQ})*{DOUBLE_QUOTE}
    LONG_STRING          {TRIBAL_QUOTE}({LONG_STRING_CHAR}|{ESCAPE_SEQ})*{TRIBAL_QUOTE}

    NON_ZERO_DIGIT       [1-9]
    DECIMAL_INTEGER      ({NON_ZERO_DIGIT}{DIGIT}*)|"0"
    FLOAT_NUMBER         {DIGIT}+"."{DIGIT}+

Syntax:

::

    Grammar

        0 $accept: testcases $end

        1 testcases: testcases single_testcase
        2          | single_testcase

        3 single_testcase: K_BEGIN ID body K_END

        4 body: K_INPUT K_EQUAL_SIGN compound K_OUTPUT K_EQUAL_SIGN compound

        5 compound: single_element
        6         | list
        7         | dict

        8 list: K_L_BRACKET elements K_R_BRACKET

        9 elements: single_element K_COMMA elements
       10         | single_element K_COMMA
       11         | single_element

       12 dict: K_L_BRACE pairs K_R_BRACE

       13 pairs: single_pair K_COMMA pairs
       14      | single_pair K_COMMA
       15      | single_pair

       16 single_pair: single_element K_COLON single_element

       17 single_element: boolean
       18               | number
       19               | string

       20 boolean: K_BOOLEAN_TRUE
       21        | K_BOOLEAN_FALSE

       22 number: DECIMAL_INTEGER
       23       | FLOAT_NUMBER

       24 string: SHORT_STRING
