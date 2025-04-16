#include <iostream>

using namespace std; // try zithout

namespace ns1 {
    void print() {
        std::cout << "ns1::print()" << std::endl;
    }
    namespace ns2 {
        void print() {
            std::cout << "ns1::ns2::print()" << std::endl;
        }
    }
}

int main() {
    ns1::print();
    ns1::ns2::print();
}
