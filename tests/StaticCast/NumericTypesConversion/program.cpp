#include <iostream>

int main() {
    int num = 10;
    double result = static_cast<double>(num); // Convert int to double

    std::cout << "Integer: " << num << "\n";
    std::cout << "Double: " << result << "\n";

    return 0;
}