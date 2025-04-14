#include <iostream>

struct C;
struct T;

struct C {
  C() {}
  C(const T&);
};

struct T {
  T() {}
  operator C() const;
};

C::C(const T& _) {
  std::cout << "conversion constructor (T -> C) is called\n";
}

T::operator C() const {
  std::cout << "conversion operator (T -> C) is called\n";
  return C();
}

int main() {
  T t;
  static_cast<C>(t);
}
