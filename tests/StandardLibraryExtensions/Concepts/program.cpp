#include <iostream>
#include <concepts>

template <std::integral T>
T square(T value) {
    return value * value;
}

int main() {
    std::cout << "Square of 5: " << square(5) << "\n";
    return 0;
}