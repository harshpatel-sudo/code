# variants - C++17

- variants are type-safe unions
- Unlike unions, variants know which type they are holding currently
- Variants are not allowed to store reference, arrays and voids (use std::variant\<std::monostate\> instead )
- allowed to store multiple fields of same type
- a default constructed variant holds value of its first alternative
- if first alternative is not default constructible, then variant is also not default constructible. -> using std::monostate allows such variants to be default constructibe

```C++
#include <variant>
#include <string>
#include <cassert>
 
int main()
{
    std::variant<int, float> v, w;
    v = 12; // v contains int
    int i = std::get<int>(v);
    w = std::get<int>(v);
    w = std::get<0>(v); // same effect as the previous line
    w = v; // same effect as the previous line
 
    //  std::get<double>(v); // error: no double in [int, float]
    //  std::get<3>(v);      // error: valid index values are 0 and 1
 
    try {
      std::get<float>(w); // w contains int, not float: will throw
    }
    catch (const std::bad_variant_access&) {}
 
    using namespace std::literals;
 
    std::variant<std::string> x("abc");
    // converting constructors work when unambiguous
    x = "def"; // converting assignment also works when unambiguous
 
    std::variant<std::string, void const*> y("abc");
    // casts to void const * when passed a char const *
    assert(std::holds_alternative<void const*>(y)); // succeeds
    y = "xyz"s;
    assert(std::holds_alternative<std::string>(y)); // succeeds
}
```