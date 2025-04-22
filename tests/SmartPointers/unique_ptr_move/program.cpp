#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr1(new int(10));
    std::unique_ptr<int> ptr2 = std::move(ptr1); // Correct!
    return 0;
}
