#include <concepts>
#include <iostream>

// Overload for integral types using std::integral concept.
template <std::integral T>
void process(T value) {
    std::cout << "Processing integral: " << value << std::endl;
}

// Overload for floating-point types using std::floating_point concept.
template <std::floating_point T>
void process(T value) {
    std::cout << "Processing floating point: " << value << std::endl;
}

int main() {
    std::cout << "Overload test using std::integral and std::floating_point:" << std::endl;
    
    process(42);      // Calls the integral overload.
    process(3.14);    // Calls the floating point overload.
    
    return 0;
}
