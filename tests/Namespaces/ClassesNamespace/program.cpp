#include <iostream>

namespace ns1 {
    class C1 {
    public:
        void print() {
            std::cout << "ns1::C1.print()" << std::endl;
        }
    };
}

class C1 {
public:
    void print() {
        std::cout << "C1.print()" << std::endl;
    }
};

int main() {
    ns1::C1 inst1;
    inst1.print();
    C1 inst2;
    inst2.print();
}