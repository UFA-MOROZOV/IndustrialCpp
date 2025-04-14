#include <iostream>

class Class {
public:
    void printName() {
        std::cout << "This is a shape." << std::endl;
    }
};

class AbstractClass : public Class {
public:
    virtual void pureVirtualFunction() = 0;
    void implementedFunction() {
        std::cout << "This is implemented function." << std::endl;
    }
    int x;
};

class ImplementedClass : public AbstractClass {
public:
    void pureVirtualFunction() {
        std::cout << "Hi!" << std::endl;
    }
};

int main() {
    ImplementedClass *implementedClass = new ImplementedClass();
    implementedClass->pureVirtualFunction();
    return 0;
}
