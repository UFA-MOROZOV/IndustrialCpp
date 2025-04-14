#include <iostream>
#include <typeinfo>
#include <cassert>

template <typename T>
class Wrapper {
public:
    T value;

    // Constructor that takes a value
    Wrapper(T val) : value(val) {
        std::cout << "[TestCase] Wrapper instantiated with T = " << typeid(T).name() 
                  << " (value constructor)\n";
    }

    // Constructor that takes a pointer and dereferences it
    Wrapper(T* ptr) : value(*ptr) {
        std::cout << "[TestCase] Wrapper instantiated with T = " << typeid(T).name() 
                  << " (pointer constructor, dereferenced value: " << value << ")\n";
    }
};

// Deduction guide is implicitly generated (no need to declare explicitly)

int main() {
    std::cout << "Running Wrapper deduction guide tests...\n";

    int x = 42;
    Wrapper w = &x;  // Deduction: Wrapper<int>
    Wrapper w1 = 42; // Deduction: Wrapper<int>

    // Assertions to validate deduction
    assert((std::is_same_v<decltype(w), Wrapper<int>>));
    assert((std::is_same_v<decltype(w1), Wrapper<int>>));

    std::cout << "[TestCase] All type deduction assertions passed! ✅\n";
    
    std::cout << "Stored values: w.value = " << w.value 
              << ", w1.value = " << w1.value << "\n";

    std::cout << "All Wrapper tests completed successfully! 🎉\n";

    return 0;
}

