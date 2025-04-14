#include <iostream>
#include <typeinfo>
#include <cassert>

// Base class with virtual function (needed for RTTI)
class Base {
public:
    virtual ~Base() = default;  // Ensure polymorphic behavior
};

class Derived : public Base {
public:
    void derivedFunction() {}
};

// Another derived class (for cross casting test)
class AnotherDerived : public Base {};

// Virtual inheritance test
class VirtualBase {
public:
    virtual ~VirtualBase() = default;
};

class DerivedFromVirtual : public virtual VirtualBase {};

// Function to test `dynamic_cast`
void test_dynamic_cast() {
    // Safe downcasting: Base* -> Derived*
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    assert(derivedPtr != nullptr && "Downcast should succeed");

    // Upcasting: Derived* -> Base* (always valid)
    Derived* d = new Derived();
    Base* b = dynamic_cast<Base*>(d);
    assert(b != nullptr && "Upcast should always succeed");

    // Cross-casting should fail
    Base* baseAnother = new AnotherDerived();
    Derived* crossCastPtr = dynamic_cast<Derived*>(baseAnother);
    assert(crossCastPtr == nullptr && "Cross cast should return nullptr");

    // Invalid downcasting should return nullptr
    Base* baseInvalid = new Base();
    Derived* invalidCast = dynamic_cast<Derived*>(baseInvalid);
    assert(invalidCast == nullptr && "Invalid downcast should return nullptr");

    // dynamic_cast with references should throw bad_cast
    try {
        Base& baseRef = *baseInvalid;
        Derived& derivedRef = dynamic_cast<Derived&>(baseRef);
        (void)derivedRef;  // Suppress unused variable warning
        assert(false && "Reference cast should have thrown std::bad_cast");
    } catch (const std::bad_cast&) {
        std::cout << "Caught std::bad_cast as expected.\n";
    }

    // Virtual base class case
    VirtualBase* vb = new DerivedFromVirtual();
    DerivedFromVirtual* dv = dynamic_cast<DerivedFromVirtual*>(vb);
    assert(dv != nullptr && "Virtual base class downcast should succeed");

    std::cout << "All dynamic casts tests passed!\n";

    // Cleanup
    delete basePtr;
    delete baseAnother;
    delete baseInvalid;
    delete d;
    delete vb;
}

int main() {
    test_dynamic_cast();
    return 0;
}
