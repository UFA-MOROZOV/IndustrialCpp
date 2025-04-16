#include <iostream>

namespace ns1 {
    void print() {
        std::cout << "ns1::print()" << std::endl;
    }
}

using namespace ns1;

int main() {
    print();
}