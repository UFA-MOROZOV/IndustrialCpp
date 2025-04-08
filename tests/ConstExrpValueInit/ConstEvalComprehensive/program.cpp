// A comprehensive consteval testset

#include <array>
#include <iostream>
#include <numeric> // Potentially needed if functions use it (ensure consteval compatibility)

// --- Global constexpr variables (can be used as arguments to consteval functions) ---
constexpr int i = 42;
constexpr double d = 3.14;
constexpr char c = 'A';

// --- Consteval Functions ---
// These MUST be evaluated at compile time.

consteval int square(int x) { return x * x; }

class Point {
public:
    // Constructor remains constexpr to allow creating constexpr objects
    constexpr Point(int x, int y) : x_(x), y_(y) {}

    // Member functions used in compile-time calculations are consteval
    consteval int x() const { return x_; }
    consteval int y() const { return y_; }
    consteval int distance_squared() const { return x_ * x_ + y_ * y_; }

private:
    int x_, y_;
};

consteval int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Consteval template function
template <typename T> consteval T max(T a, T b) { return a > b ? a : b; }

// Consteval function using a constexpr global array
// (The array itself is constexpr, the function using it is consteval)
constexpr std::array<int, 3> arr_global = {1, 2, 3};
consteval int array_sum() { return arr_global[0] + arr_global[1] + arr_global[2]; }

consteval int fibonacci(int n) {
    if (n <= 1)
        return n;
    // Recursive calls must also resolve at compile time
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // All tests must use compile-time constants and static_assert,
    // as consteval functions cannot be called at runtime.

    // Basic variables (still constexpr)
    static_assert(i == 42);
    static_assert(d == 3.14);
    static_assert(c == 'A');

    // Function evaluation (must use compile-time args)
    static_assert(square(5) == 25);
    // int runtime_square = square(6); // COMPILE ERROR! consteval function called at runtime

    // Class usage (object must be constexpr)
    constexpr Point p(3, 4);
    static_assert(p.distance_squared() == 25);
    constexpr Point origin(0, 0);
    static_assert(origin.distance_squared() == 0);
    static_assert(p.x() == 3); // Calling consteval member function

    // Loop and recursion (evaluated fully at compile time)
    static_assert(factorial(5) == 120);
    static_assert(fibonacci(10) == 55);

    // Template function (must use compile-time args)
    static_assert(max(5, 10) == 10);
    static_assert(max(3.14, 2.71) == 3.14);

    // Standard library containers (function accessing global constexpr array)
    static_assert(array_sum() == 6);
    static_assert(arr_global.size() == 3); // Accessing constexpr global directly
    
    std::cout << "Tests passed!\n";
    return 0;
}