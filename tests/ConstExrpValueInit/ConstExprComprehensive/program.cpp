// A comprehensive constexpr testset

#include <array>
#include <iostream>

constexpr int i = 42;
constexpr double d = 3.14;
constexpr char c = 'A';

constexpr int square(int x) { return x * x; }

class Point {
public:
  constexpr Point(int x, int y) : x_(x), y_(y) {}
  constexpr int x() const { return x_; }
  constexpr int y() const { return y_; }
  constexpr int distance_squared() const { return x_ * x_ + y_ * y_; }

private:
  int x_, y_;
};

constexpr int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

constexpr auto add = [](int a, int b) constexpr { return a + b; };

template <typename T> constexpr T max(T a, T b) { return a > b ? a : b; }

constexpr std::array<int, 3> arr = {1, 2, 3};
constexpr int array_sum() { return arr[0] + arr[1] + arr[2]; }

constexpr int fibonacci(int n) {
  if (n <= 1)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  // Basic variables
  static_assert(i == 42);
  static_assert(d == 3.14);
  static_assert(c == 'A');

  // Function evaluation
  static_assert(square(5) == 25);
  int runtime_square = square(6); // Runtime evaluation
  std::cout << "Runtime square: " << runtime_square << '\n';

  // Class usage
  constexpr Point p(3, 4);
  static_assert(p.distance_squared() == 25);
  constexpr Point origin(0, 0);
  static_assert(origin.distance_squared() == 0);

  // Loop and recursion
  static_assert(factorial(5) == 120);
  static_assert(fibonacci(10) == 55);

  // Lambda expression
  static_assert(add(2, 3) == 5);
  constexpr auto sub = [](int a, int b) constexpr { return a - b; };
  static_assert(sub(5, 3) == 2);

  // Template function
  static_assert(max(5, 10) == 10);
  static_assert(max(3.14, 2.71) == 3.14);

  // Standard library containers
  static_assert(array_sum() == 6);
  static_assert(arr.size() == 3);

  std::cout << "Tests passed!\n";
  return 0;
}
