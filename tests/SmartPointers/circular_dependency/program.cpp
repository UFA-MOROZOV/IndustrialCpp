#include <iostream>
#include <memory>

class A {
public:
    std::shared_ptr<B> b_ptr;
};

class B {
public:
    std::shared_ptr<A> a_ptr;
};

std::weak_ptr<B> weak;

void circularDependencySolved() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    weak = b;
    a->b_ptr = b;
    b->a_ptr = a;
}

int main() {
    circularDependencySolved();
    if (auto lockedPtr = weak.lock()) {
        std::cout << "Object is still alive: " << lockedPtr.get() << std::endl;
    }
    else {
        std::cout << "Object has been deleted" << std::endl;
    }
}
