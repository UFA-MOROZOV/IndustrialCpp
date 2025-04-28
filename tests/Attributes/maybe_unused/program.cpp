#include <iostream>

[[maybe_unused]] int x = 42;
int y = 42;

void myFunction([[maybe_unused]] int param) {
    std::cout << "Parameter might not be used." << std::endl;
}

[[maybe_unused]] void unusedFunction() {
    std::cout << "This function might not be used." << std::endl;
}

[[maybe_unused]]
struct MyStruct {
    int value;
};

[[maybe_unused]] enum MyEnum { A, B, C };

int main() {

    return 0;
}