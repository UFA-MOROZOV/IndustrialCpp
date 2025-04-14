#include <iostream>
#include <cassert>

struct A { int x; };
struct B { double y; };

using FuncType1 = void (*)();
using FuncType2 = int (*)(int);

void test_reinterpret_cast() {

    FuncType1 func1 = []() { std::cout << "Hello" << std::endl; };
    FuncType2 func2 = reinterpret_cast<FuncType2>(func1); // Undefined behavior if called
    assert(reinterpret_cast<FuncType1>(func2) == func1);

    // 8. Function pointer to object pointer (conditionally-supported, implementation-defined)
    A* objP = reinterpret_cast<A*>(func1);
    auto value = objP->x;
    std::cout << value;
    objP->x = 42;

    FuncType1 func3 = reinterpret_cast<FuncType1>(objP);
    assert(func3 == func1);
    std::cout << "Function pointer to struct conversion do work !!!";
}

int main() {
    test_reinterpret_cast();
    return 0;
}
