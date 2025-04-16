#include <iostream>

namespace ns1 {
    class C1{
        public:
        void print();
    };
    void print();
}

void ns1::print() {
    std::cout << "ns1::print()" << std::endl;
}
void ns1::C1::print() {
    std::cout << "ns1::C1.print()" << std::endl;
}

int main() {
    ns1::C1 inst;
    inst.print();
    ns1::print();
}