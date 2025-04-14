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
    {
        // Virtual base class case (C-style casts don't check virtual hierarchy)
        VirtualBase* vb = new DerivedFromVirtual();
        DerivedFromVirtual* dv = (DerivedFromVirtual*)vb;
        assert(dv != nullptr && "C-style cast does not check virtual base class hierarchy");
        delete vb;
    }
    {
        const int* i;
        auto x = (int*)i;
    }
}

int main() {
    test_c_style_cast();
    return 0;
}
