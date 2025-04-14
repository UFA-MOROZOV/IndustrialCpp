class Base {};
class Derived : public Base {};

int main()
{
    Derived dObj;
    // Upcasting
    Base* basePtr = static_cast<Base*>(&dObj);

    // Downcasting
    Derived* derivedPtr = static_cast<Derived*>(basePtr);
    return 0;
}
