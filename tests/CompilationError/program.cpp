#include <iostream>

class AbstractClass {
public:
    virtual void pureVirtualFunction() = 0;
    void implementedFunction() {
        std::cout << "This is implemented function." << std::endl;
    }
    int x;
};

class ImplementedClass : public AbstractClass {
public:
    void function() {
        std::cout << "Hi!" << std::endl;
    }
};

int main() {
    ImplementedClass *implementedClass = new ImplementedClass();
    implementedClass->pureVirtualFunction();
    return 0;
}
