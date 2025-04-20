#include <iostream>
#include <memory>

int main() {
    // Without make_unique
    std::unique_ptr<int> ptr1(new int(42));
    // With make_unique
    auto ptr2 = std::make_unique<int>(42);
    return 0;
}
