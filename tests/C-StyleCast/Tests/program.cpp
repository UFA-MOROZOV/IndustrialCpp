#include <iostream>
#include <cassert>
#include <typeinfo>

class Base {
public:
    virtual ~Base() = default;  // Needed for runtime type information (RTTI)
};

class Derived : public Base {
public:
    void derivedFunction() {}
};

class AnotherDerived : public Base {};

// Virtual inheritance test
class VirtualBase {
public:
    virtual ~VirtualBase() = default;
};

class DerivedFromVirtual : public virtual VirtualBase {};

// Function to test C-style casts
void test_c_style_cast() {
    // Safe downcasting using C-style cast (Base* -> Derived*)
    Base* basePtr = new Derived();
    Derived* derivedPtr = (Derived*)basePtr;  // Unsafe, but works if the object is truly Derived
    assert(derivedPtr != nullptr && "C-style cast downcast should work if the object is actually Derived");

    // Upcasting: Always valid (Derived* -> Base*)
    Derived* d = new Derived();
    Base* b = (Base*)d;
    assert(b != nullptr && "C-style cast upcast should always succeed");

    // Cross-casting: C-style cast does not check type safety!
    Base* baseAnother = new AnotherDerived();
    Derived* crossCastPtr = (Derived*)baseAnother;  // Dangerous!
    assert(crossCastPtr != nullptr && "C-style cast does not return nullptr on invalid cast");

    // Invalid downcasting: C-style cast does not return nullptr (potentially undefined behavior)
    Base* baseInvalid = new Base();
    Derived* invalidCast = (Derived*)baseInvalid;  // May cause undefined behavior if accessed
    assert(invalidCast != nullptr && "C-style cast does not check types, can cause UB");

    // Reference cast (doesn't throw like dynamic_cast)
    try {
        Base& baseRef = *baseInvalid;
        Derived& derivedRef = (Derived&)baseRef;  // Undefined behavior if incorrect
        (void)derivedRef;
        std::cout << "C-style reference cast executed (may be incorrect but compiles).\n";
    } catch (...) {
        assert(false && "C-style reference cast should not throw.");
    }

    // Cleanup
    delete basePtr;
    delete baseAnother;
    delete baseInvalid;
    delete d;

    std::cout << "All tests on C-style casts work !!!";
}

int main() {
    test_c_style_cast();
    return 0;
}
