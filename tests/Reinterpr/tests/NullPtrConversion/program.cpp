#include <iostream>
#include <cassert>
#include <cstdint>

void test_reinterpret_cast() {
    // 4. nullptr_t conversion
    std::nullptr_t np;
    std::uintptr_t np_int = reinterpret_cast<std::uintptr_t>(static_cast<void*>(nullptr));
    assert(np_int == 0);
}

int main() {
    test_reinterpret_cast();
    std::cout << "Nullptr_t conversions work !!!";
    return 0;
}
