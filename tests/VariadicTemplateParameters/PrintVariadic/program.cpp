#include <iostream>

template<typename... Args>
void printAll(Args... args) {
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
}

int main() {
    std::cout << "Printing a series of arguments:" << std::endl;
    printAll("Variadic", "template", "parameters", "are", "powerful!");
    printAll(100, 200, 300, 400, 500);
    return 0;
}
