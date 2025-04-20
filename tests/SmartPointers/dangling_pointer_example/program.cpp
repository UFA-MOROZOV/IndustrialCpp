#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <chrono>

int* createNumber(int value) {
    // some calculations...
    int a = value + 1;
    return &a;
}

void example() {
    int* num = createNumber(1);
    // Var a is already deleted (out of scope)
    // so num is a dangling pointer now
    std::cout << *num << std::endl; // UB
}

int main() {
    example();

    return 0;
}
