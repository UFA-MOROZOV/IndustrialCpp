#include <type_traits>

int multiply(int a, int b) {
    return a * b;
}
int main() {
    decltype(multiply(2, 3)) result;
    static_assert(std::is_same_v<decltype(result), int>, "Result type is not int");
}