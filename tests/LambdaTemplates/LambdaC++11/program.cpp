#include <iostream>
#include <functional>

template <typename T>
std::function<void(T)> h_c11(T x) {
    // we can return lambda function
    return [](T x){ std::cout << "Received param (C++ 11): " << x << "\n"; };
}

int main() {
    h_c11(true)(1);
    // std::cout << "Received param (C++ 11): 1\n";
}

