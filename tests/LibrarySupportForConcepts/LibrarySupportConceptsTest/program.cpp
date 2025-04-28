#include <concepts>
#include <iostream>
#include <type_traits>

// Custom concept to check if type T supports addition and the result is convertible to T.
template<typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
};

// Function template that uses the custom Addable concept.
// This function will only compile for types that satisfy the Addable concept.
template<Addable T>
T add(T a, T b) {
    return a + b;
}

// Function template that uses the built-in standard library concept std::integral
// This ensures that only integral types are accepted.
template<std::integral T>
T multiply(T a, T b) {
    return a * b;
}

int main() {
    std::cout << "Testing add function with Addable concept:" << std::endl;
    std::cout << "5 + 10 = " << add(5, 10) << std::endl;

    std::cout << "\nTesting multiply function with std::integral concept:" << std::endl;
    std::cout << "4 * 7 = " << multiply(4, 7) << std::endl;
    
    // Uncomment the following line to see a compile-time error:
    // because double does not satisfy std::integral.
    // std::cout << "3.5 * 2.0 = " << multiply(3.5, 2.0) << std::endl;

    return 0;
}
