#include <iostream>
#include <cassert>

struct A { int x; };
struct B { double y; };


void test_reinterpret_cast() {
    // 7. Object pointer conversion
    A objA;
    B* objB = reinterpret_cast<B*>(&objA);
    assert(reinterpret_cast<A*>(objB) == &objA);
}

int main() {
    test_reinterpret_cast();
    std::cout << "Object pointer conversions do work !!!";
    return 0;
}
