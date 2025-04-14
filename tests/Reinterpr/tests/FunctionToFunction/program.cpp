#include <iostream>
#include <cassert>

using FuncType1 = void (*)();
using FuncType2 = int (*)(int);

void test_reinterpret_cast() {
    // 6. Function pointer conversion
    FuncType1 func1 = []() { std::cout << "Hello" << std::endl; };
    FuncType2 func2 = reinterpret_cast<FuncType2>(func1); // Undefined behavior if called
    assert(reinterpret_cast<FuncType1>(func2) == func1);
    std::cout << "Function ptr conversions do work !!!";
}

int main() {
    test_reinterpret_cast();
    return 0;
}
