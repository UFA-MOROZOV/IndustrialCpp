#include <algorithm>
#include <concepts>
#include <iostream>
#include <vector>

// Function template using std::integral concept ensures only integral types are processed.
template<std::integral T>
void print_doubles(const std::vector<T>& data) {
    std::for_each(data.begin(), data.end(), [](const T& value) {
        std::cout << (value * 2) << " ";
    });
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = { 1, 2, 3, 4, 5 };
    print_doubles(data); // should output: 2 4 6 8 10
    return 0;
}
