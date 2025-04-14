#include <iostream>
#include <cassert>
#include <cstdint>

using FuncType1 = void (*)();
using FuncType2 = int (*)(int);

void test_reinterpret_cast() {
    // 1. Checking reference conversions
    int a = 10;
    int& a_ref = a;

    int* p = &a;
    void* vp = reinterpret_cast<void*>(p);
    int* p2 = reinterpret_cast<int*>(vp);
    assert(p == p2);

    // 3. Pointer to integer conversion (implementation-defined mapping)
    std::uintptr_t addr = reinterpret_cast<std::uintptr_t>(p);
    int* p3 = reinterpret_cast<int*>(addr);
    assert(p == p3);

    // 5. Integer to pointer conversion
    int* p4 = reinterpret_cast<int*>(addr);
    assert(p4 == p);

    std::cout << "Int to ptr and back conversions do work!!!";
}

int main() {
    test_reinterpret_cast();
    return 0;
}
