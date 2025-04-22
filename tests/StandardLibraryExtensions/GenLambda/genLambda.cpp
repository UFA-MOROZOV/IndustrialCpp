// since c++ 14
#include <iostream>

int main() {
    auto generic_lambda = [](auto x, auto y) { return x + y; };
    std::cout << generic_lambda(5, 10) << '\n';
    std::cout << generic_lambda(3.5, 2.1) << '\n';
}
