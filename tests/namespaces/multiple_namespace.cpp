#include <iostream>

namespace ns1 {
    void print() {
        std::cout << "ns1::print()" << std::endl;
    }
}

namespace ns2 {
    void print() {
        std::cout << "ns2::print()" << std::endl;
    }
}

void main() {
    ns1::print();
    ns2::print();
}
