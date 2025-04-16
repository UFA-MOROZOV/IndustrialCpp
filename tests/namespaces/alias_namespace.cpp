#include <iostream>

namespace ns1 {
    namespace ns2 {
        namespace ns3 {
            void print() {
                std::cout << "ns1::ns2::ns3::print()" << std::endl;
            }
        }
    }
}

namespace alias = ns1::ns2::ns3;

int main() {
    alias::print();
}