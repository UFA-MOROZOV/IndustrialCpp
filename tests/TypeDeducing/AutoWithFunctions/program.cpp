#include <iostream>

template<typename T, typename U>
auto sum(T a, U b) -> decltype(a + b) { // Use trailing return type
    return a + b;
}

int main() {
    static_assert(std::is_same_v<decltype(sum(2, 3)), int>, "Sum result is not int");
    static_assert(std::is_same_v<decltype(sum(2.5, 3)), double>, "Sum result is not double");
}