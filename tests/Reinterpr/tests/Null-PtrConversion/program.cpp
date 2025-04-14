#include <iostream>
#include <cassert>

void test_reinterpret_cast() {
    // 9. Null pointer conversion
    int* nullPtr = nullptr;
    void* voidNullPtr = reinterpret_cast<void*>(nullPtr);
    assert(voidNullPtr == nullptr);
}

int main() {
    test_reinterpret_cast();
    std::cout << "Nullptr conversions do work !!!";
    return 0;
}
