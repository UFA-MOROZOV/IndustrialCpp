#include <iostream>
#include <concepts>

template<typename T>
concept Printable = requires(std::ostream& os, T val) {
    { os << val } -> std::convertible_to<std::ostream&>;
};

int main() {
    auto print_value = []<typename T>(const T& val) {
        std::cout << "Received param (C++ 20): " << val << "\n";
    };
    print_value("Hello!");
}
