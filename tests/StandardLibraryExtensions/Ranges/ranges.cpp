// since c++ 20
#include <ranges>
#include <vector>
#include <iostream>

int main() {
    std::vector nums = {1, 2, 3, 4, 5};

    for (int n : nums | std::views::reverse) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}
