// Static creation of object with constexpr constructor

#include <iostream>

class Simple {
public:
  constexpr Simple(int val) : value(val) {}

  constexpr int getValue() const { return value; }

private:
  int value;
};

int main() {
  constexpr Simple obj(42);
  static_assert(obj.getValue() == 42); // Object is created in compile time

  std::cout << obj.getValue();
}
