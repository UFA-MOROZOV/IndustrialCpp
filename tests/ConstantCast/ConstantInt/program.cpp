// Valid usage of const cast – removing constness from ref. to initially non-const value.

#include <iostream>

int main() {
  int x = 5;

  const int& crx = x;
  int &rx = const_cast<int&>(crx);

  x = 6;
  std::cout << x;
}
