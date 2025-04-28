// since c++ 20
#include <iostream>

template<typename T>
concept Integral = std::is_integral_v<T>;

template<Integral T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(3, 4) << '\n';
    // add(3.5, 2.5); // should fail, uncomment to test failure
}
