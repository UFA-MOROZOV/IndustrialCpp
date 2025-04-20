#include <iostream>

class Empty1 {};
class Empty2 {};
class Empty3 {};
class Empty4 {};

class WithAttribute {
public:
    [[no_unique_address]] Empty1 e1;
    [[no_unique_address]] Empty2 e2;
    [[no_unique_address]] Empty3 e3;
    [[no_unique_address]] Empty4 e4;
    int x;
};

int main() {
    std::cout << "WithAttribute size: " << sizeof(WithAttribute) << std::endl;
}