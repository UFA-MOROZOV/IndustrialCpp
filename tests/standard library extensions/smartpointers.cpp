// since c++ 11
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> ptr = std::make_shared<int>(10);
    std::cout << "Shared pointer value: " << *ptr << '\n';
}
