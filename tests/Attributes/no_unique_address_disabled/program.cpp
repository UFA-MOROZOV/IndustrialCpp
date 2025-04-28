#include <iostream>

class Empty {};

class WithoutAttribute {
public:
    Empty e;
    int x;
};

int main() {
    std::cout << "WithoutAttribute size:\n"
        << sizeof(WithoutAttribute) << std::endl;
}

