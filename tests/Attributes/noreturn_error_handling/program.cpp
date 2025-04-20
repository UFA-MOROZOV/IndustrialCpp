#include <iostream>

[[noreturn]] int noReturnFunction() {
    std::cout << "noReturnFunction is called!\n";
    throw std::runtime_error("An error occurred!");
}

int main() {
    try {
        noReturnFunction();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Exit from noReturnFunction!\n";
    noReturnFunction();
    std::cout << "Exit from noReturnFunction!\n";

    return 0;
}