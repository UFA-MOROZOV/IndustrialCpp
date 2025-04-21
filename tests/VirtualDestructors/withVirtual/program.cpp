#include <iostream>
#include <vector>

class A {
public:
    A() { std::cout << "A constructor\n"; }
    virtual ~A() { std::cout << "A destructor\n"; }
};

class B : public A {
public:
    B() { std::cout << "B constructor\n"; }
    ~B() { std::cout << "B destructor\n"; }
private:
    std::vector<int> v = { 1, 2, 3, 4, 5 };
};

int main() {
   A* obj = new B();
   delete obj; 
   return 0;
}


