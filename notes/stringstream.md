# stringstream

Convert anytype to String

```C++

#include<sstream>
#include<iostream>

template<typename T>
std::string to_string(const T& t) {
    std::stringstream ss;
    ss <<t;
    return ss.str();
}

```