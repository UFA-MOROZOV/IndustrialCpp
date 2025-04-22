#include <iostream>
#include <type_traits>

int main() {
    auto x = 42;
    auto y = 3.14;
    auto z = "Hello";
    
    static_assert(std::is_same_v<decltype(x), int>, "x is not int");
    static_assert(std::is_same_v<decltype(y), double>, "y is not double");
    static_assert(std::is_same_v<decltype(z), const char*>, "z is not const char*");
}