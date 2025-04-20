#include <iostream>
#include <memory>

int main() {
    std::auto_ptr<int> ptr1(new int(10));
    std::auto_ptr<int> ptr2 = ptr1; // ptr1 becomes nullptr
    std::cout << *ptr1 << std::endl << *ptr2 << std::endl;
}