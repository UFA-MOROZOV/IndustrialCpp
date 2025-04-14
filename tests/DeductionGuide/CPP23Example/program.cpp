#include <iostream>

template<class T, class D = int>
struct S {
    T data;

    S(T value) : data(value) {  
        std::cout << "Constructor called with T = " << typeid(T).name() << "\n";
    }
};

template<class U>
S(U) -> S<typename U::type>;  // Deduction guide: U::type determines T

struct A {
    using type = short;
    operator type() { 
        std::cout << "A::operator short() called\n";
        return 42; 
    }
};

S x{A()};  // Uses deduction guide: S(A()) -> S<A::type> -> S<short>

int main() {
    std::cout << "Example from C++23 standard (n4950) compiles!\n";
    std::cout << "Stored value in x: " << x.data << "\n";
    std::cout << "Example from C++23 standard (n4950) works!\n";
}

