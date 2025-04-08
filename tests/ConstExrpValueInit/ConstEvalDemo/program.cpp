#include <iostream>

// Consteval function: must be evaluated at compile-time
consteval int square_consteval(int x) {
    return x * x;
}

// Constexpr function for comparison
constexpr int square_constexpr(int x) {
    return x * x;
}

int main() {
    // Works: square_consteval called with compile-time constant
    std::cout << square_consteval(12) << std::endl;

    int x;
    std::cin >> x;

    // Compiles: square_constexpr can be called with runtime variable
    std::cout << square_constexpr(x) << std::endl;

    // Error: square_consteval cannot be called with runtime variable 'x'
    // std::cout << square_consteval(x);

    return 0;
}