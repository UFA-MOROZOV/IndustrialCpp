#include <iostream>
#include <cassert>

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
}

int main() {
    test_reinterpret_cast();
    std::cout << "Reference conversions do work !!!";
    return 0;
}
