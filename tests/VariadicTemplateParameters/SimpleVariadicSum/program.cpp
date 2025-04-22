#include <iostream>

template<typename... Args>
auto variadicSum(Args... args) {
    return (args + ...);
}

int main() {
    std::cout << "Sum of 1, 2, 3: " << variadicSum(1, 2, 3) << std::endl;          
    std::cout << "Sum of 10, 20, 30, 40: " << variadicSum(10, 20, 30, 40) << std::endl; 
    return 0;
}
