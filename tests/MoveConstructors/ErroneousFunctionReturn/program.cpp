#include <vector>

class A {
public:
    std::vector<int> v = { 11 };

    A() = default;
    ~A() = default;

    A(const A&) = default;

    A(A&&) = delete;
};

A foo() {
    A ret;

    // Tries to use move constructor, though copy would also be valid
    return ret;
    
    // This would've worked
    // return A(ret);
}

int main() {
    A a = foo();
    return 0;
}