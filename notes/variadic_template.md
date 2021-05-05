# Variadic Templates

- Can take variable number of template arguments (of same or different types )
- Expands itself in place

```C++
#include<vector>
template<typename T>
std::string to_string_impl(const T& t) {
    std::stringstream ss;
    ss <<t;
    return ss.str();
}

std::vector<std::string> to_string() { return (); }

// "Param& ... param" is template parametr Pack
// "param ..." is function parameter pack
// Recursive calls to "to_string" function to unpack all arguments i.e. call one by one
template<typename P1, typename ... Param>
std::vector<std::string> to_string(cosnt P1& p1, const Param& ... param) {
    std::vector<std::string> s;
    s.push_back(to_string_impl(p1)); // basecase
    const auto remainder = to_string(param...);
    s.insert(s.end(),remainder.being(),remainder.end()); // recursive call
    return s;
}

int main() {
    std::vector<std::string> s = to_string(1,2.0, "Hello", 52, "World"); // Can take multiple types of argument
}

```