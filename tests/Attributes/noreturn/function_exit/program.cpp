#include <iostream>

[[noreturn]] int noReturnFunction() {
    std::cout << "noReturnFunction is called!\n";
    std::exit(1);
//    std::abort();
}

int main() {
    noReturnFunction();
    std::cout << "Exit from noReturnFunction!\n";
    return 0;
}