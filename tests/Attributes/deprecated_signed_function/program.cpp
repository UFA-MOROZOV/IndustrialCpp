#include <iostream>

[[deprecated("This function is deprecated, use newFunction instead!")]] void oldFunction() {
    std::cout << "This is old function!\n";
}

void newFunction() {
    std::cout << "This is new function!\n";
}

int main() {
    oldFunction();
    newFunction();
    return 0;
}