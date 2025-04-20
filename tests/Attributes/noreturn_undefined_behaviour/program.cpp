#include <iostream>

[[noreturn]] int noReturnFunction() {
    std::cout << "noReturnFunction is called!\n";
}

int main() {
    noReturnFunction();
    std::cout << "Exit from noReturnFunction!\n";
    return 0;
}

