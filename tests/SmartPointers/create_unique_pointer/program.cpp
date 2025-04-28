#include <iostream>

void exampleCreateUniquePtr() {
    std::unique_ptr<int> ptr = std::make_unique<int>(42);

    *ptr = 100;
    std::cout << *ptr << std::endl;
}

int main() {
    exampleCreateUniquePtr();
}
