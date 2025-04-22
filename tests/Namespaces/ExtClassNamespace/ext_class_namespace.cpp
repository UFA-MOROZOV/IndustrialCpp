#include <iostream>

namespace ns1 {
    class C1;
}

class ns1::C1 {
    public:
    void print() {
        std::cout << "ns1::C1.print()" << std::endl;
    }
};

int main() {
    ns1::C1 inst;
    inst.print();
}