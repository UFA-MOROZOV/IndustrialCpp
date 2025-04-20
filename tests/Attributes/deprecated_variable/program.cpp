#include <iostream>

[[deprecated("Use newVariable instead")]]
const double oldPI = 3.14;

const double newPI = 3.1415926535;

int main() {
    std::cout.precision(15);
    std::cout << oldPI << std::endl;
    std::cout << newPI << std::endl;
    return 0;
}