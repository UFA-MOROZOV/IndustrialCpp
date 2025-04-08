// A comprehensive constinit testset

#include <array>
#include <iostream>

// --- Supporting constexpr functions/types needed for initializers ---
constexpr int square(int x) { return x * x; }

class Point {
public:
    // Constructor must be constexpr for constant initialization
    constexpr Point(int x, int y) : x_(x), y_(y) {}
    constexpr int x() const { return x_; }
    constexpr int y() const { return y_; }
    constexpr int distance_squared() const { return x_ * x_ + y_ * y_; }

private:
    int x_, y_;
};

constexpr int factorial(int n) {
    // Note: C++14 allows loops in constexpr.
    // For C++11, recursion would be needed.
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

constexpr auto add = [](int a, int b) constexpr { return a + b; };

template <typename T> constexpr T max(T a, T b) { return a > b ? a : b; }

constexpr int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
// --- End of supporting constexpr functions/types ---


// --- constinit Global Variables ---
// Initialized at compile time using constant expressions.

constinit int i = 42;
constinit double d = 3.14;
constinit char c = 'A';

// Initialized using a constexpr function
constinit int i_squared = square(10); // 100

// Initialized using a constexpr constructor
constinit Point p(3, 4);

// Initialized using a constexpr recursive function
constinit int fact5 = factorial(5); // 120

// Initialized using a constexpr lambda
constinit int sum_lambda = add(10, 20); // 30

// Initialized using a constexpr template function
constinit double max_val = max(3.14, 2.71); // 3.14

// Initialized using a constexpr recursive function
constinit int fib10 = fibonacci(10); // 55

// A global array initialized with compile-time constants
constinit std::array<int, 3> arr = {1, 2, 3};

// A constinit variable that is *not* const, so it can be modified later.
constinit int modifiable_counter = 100;


int main() {
    // Verify initial values (implicitly tests compile-time initialization)
    // We can't use static_assert directly on non-const global variables inside main,
    // but we can print them or use them in ways that show their initial state.
    std::cout << "Initial values:\n";
    std::cout << "i: " << i << " (Expected: 42)\n";
    std::cout << "d: " << d << " (Expected: 3.14)\n";
    std::cout << "c: " << c << " (Expected: A)\n";
    std::cout << "i_squared: " << i_squared << " (Expected: 100)\n";
    std::cout << "p.distance_squared(): " << p.distance_squared() << " (Expected: 25)\n";
    std::cout << "fact5: " << fact5 << " (Expected: 120)\n";
    std::cout << "sum_lambda: " << sum_lambda << " (Expected: 30)\n";
    std::cout << "max_val: " << max_val << " (Expected: 3.14)\n";
    std::cout << "fib10: " << fib10 << " (Expected: 55)\n";
    std::cout << "arr[1]: " << arr[1] << " (Expected: 2)\n";
    std::cout << "modifiable_counter: " << modifiable_counter << " (Expected: 100)\n";

    // Demonstrate modification of a non-const constinit variable
    modifiable_counter += 50;
    std::cout << "\nModified counter: " << modifiable_counter << " (Expected: 150)\n";

    // Attempting to use a runtime variable for constinit would fail compilation:
    // int runtime_var = 10;
    // constinit int error_init = runtime_var; // COMPILE ERROR!

    std::cout << "\nConstinit tests completed (verification via output).\n";
    return 0;
}