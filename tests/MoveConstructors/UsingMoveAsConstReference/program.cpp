#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class A {
public:
    std::vector<int> v = { 11 };

    A() = default;
    A(const A&) = default;

    // As per rules, compiler didn't implement move constructor
    // And we're not deleting it explicitly
    // to allow rvalue transformation and the use of copy constructor
    // A(A&&) = delete;
};

int main() {
    A a;
    A b(std::move(a));

    // 'a' still valid
    assert(a.v[0] == 11);
    return 0;
}