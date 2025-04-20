#include <iostream>

[[noreturn]] int noReturnFunction1() {
    std::cout << "noReturnFunction is called!\n";
    while(true);
}

int main() {
    noReturnFunction1();
    std::cout << "Exit from noReturnFunction!\n";
    return 0;
}