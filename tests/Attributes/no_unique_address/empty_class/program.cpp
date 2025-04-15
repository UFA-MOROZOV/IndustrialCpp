#include <iostream>

class Empty {};

class WithAttribute {
public:
    [[no_unique_address]] Empty e;
    int x;
};

int main() {
    std::cout << "WithAttribute size:\n"
        << sizeof(WithAttribute) << std::endl;
    return 0;
}