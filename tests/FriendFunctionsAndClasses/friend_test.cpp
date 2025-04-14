#include <iostream>

class A {
 private:
  void printA() const { std::cout << "Print A" << std::endl; }

  friend class B;
};

class B {
 private:
  void printB() const { std::cout << "Print B" << std::endl; }

  friend class C;
};

class C {
 public:
  C(const B &b) { b.printB(); }
  // C(const A &a) { a.printA(); } // 'printA' is a private member of 'A'
};
