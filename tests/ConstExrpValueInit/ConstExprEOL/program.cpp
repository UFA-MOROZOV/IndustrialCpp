// Constexpr + Concepts EOL of function
#include <iostream>

template <int expirationYear> constexpr bool isBeforeYear() {
  const int curYear = (__DATE__[7] - '0') * 1000 + (__DATE__[8] - '0') * 100 +
                      (__DATE__[9] - '0') * 10 + (__DATE__[10] - '0');
  return curYear < expirationYear;
}

template <class T>
int functionWithEOL()
  requires(isBeforeYear<2026>())
{
  return 2025;
}

int main() {
  functionWithEOL<int>();
  std::cout << "In 2026 this code won't compile :)";
}
