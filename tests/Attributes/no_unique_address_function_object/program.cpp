#include <iostream>

struct EmptyFunctor {
    void operator()() const {
        std::cout << "EmptyFunctor called!" << std::endl;
    }
};

class MyClass {
public:
    MyClass() = default;

    void performAction() {
        functor();
    }

private:
    int x = 42;
    [[no_unique_address]] EmptyFunctor functor;
};

int main() {
    MyClass obj;
    obj.performAction();
    std::cout << "Size of MyClass: " << sizeof(MyClass) << std::endl;
    return 0;
}