#include <iostream>

namespace ns1 {
    int x = 1; // namespace variable

    // also works with functions
    void print() {
        std::cout << "ns1::print()" << std::endl;
    }
}

void print() {
    std::cout << "print()" << std::endl;
}

int main() {
    int x = 2; // local function variable 
    std::cout << x << std::endl;
    std::cout << ns1::x << std::endl;

    print();
    ns1::print();
}