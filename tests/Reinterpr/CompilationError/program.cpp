#include <iostream>
#include <cassert>
#include <cstdint>
#include <type_traits>

void test_reinterpret_cast() {
    // 2. Casting away constness (invalid, should cause a compile error)
    const int c = 5;
    int* pc = reinterpret_cast<int*>(&c); // ERROR: invalid cast
}

int main() {
    test_reinterpret_cast();
    return 0;
}
