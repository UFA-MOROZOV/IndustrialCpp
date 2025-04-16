// since c++ 14
#include <memory>
#include <iostream>

int main() {
    auto ptr = std::make_unique<int>(42);
    std::cout << "Unique pointer value: " << *ptr << '\n';
}
