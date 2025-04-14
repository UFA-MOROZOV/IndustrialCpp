#include <iostream>

auto lambda_14 = [](auto x){ std::cout << "Received param (C++ 14): " << x << "\n"; };

int main() {
    lambda_14(31337);
}
