// Attempt to update value under const class instance, compiles, but UB.

#include <iostream>

struct C {
  int x = 21;
  void upd() const {
    const_cast<C*>(this)->x = 42;
  }
};

int main() {
  const C c;
  c.upd();
  std::cout << c.x;
}
