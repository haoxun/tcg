# What is `tcg`

`tcg` stands for "TestCase Generator". With `tcg`, you can write testcases in a way that is **language independent**, and generate code for specific language.

Syntax of `tcg` is simple:

```
begin <test-id>
input = <input value>
output = <output value>
end
```
where `<test-id>` defines the name/id of testcase, `<input value>` defines the input value, and `<output value>` defines expected output value.

For example:

```
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
```

By scanning previous testcases definition, `tcg` can generate code for C++ googletest framework:

```
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
```
