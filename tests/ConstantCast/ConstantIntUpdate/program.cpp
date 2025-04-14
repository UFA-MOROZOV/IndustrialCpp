// Attempt to update underlying constant. Compiles, but UB

#include <iostream>

int main() {
  const int c = 3;
  int* p = const_cast<int*>(&c);
  *p = 4;
  std::cout << c << ' ' << *p;
}
