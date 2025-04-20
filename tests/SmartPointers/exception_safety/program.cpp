#include <iostream>
#include <memory>
#include <stdexcept>

void doSomething() {
    throw std::runtime_error("Exception from doSomething");
}

void exampleWithoutUniquePtr() {
    int* raw = new int(10);
    try {
        doSomething();
    }
    catch (...) {
        delete raw;
        throw;
    }
    delete raw;
}

void exampleWithUniquePtr() {
    auto ptr = std::make_unique<int>(10);
    try {
        doSomething();
    }
    catch (...) {
        throw;
    }
}

int main() {
    try {
        exampleWithoutUniquePtr();
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        exampleWithUniquePtr();
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}
