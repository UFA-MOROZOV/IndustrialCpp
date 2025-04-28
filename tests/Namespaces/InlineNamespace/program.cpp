#include <iostream>
#include <stdexcept>

namespace ns1 {
    inline namespace ns2 {
        void print() {
            std::cout << "ns1::ns2::print()" << std::endl;
        }
    }

    // Produces error
    // void print() {
    //     std::cout << "ns1::print()" << std::endl;
    // }
}

int main () {
    ns1::print();
}