#include <iostream>
#include <utility>
#include <type_traits>
#include <cassert>

int main() {
    std::cout << "Running std::pair deduction guide test...\n";

    // Deduction guide automatically deduces std::pair<int, double>
    std::pair p = {42, 3.14};  

    // Assertions to validate deduction
    assert((std::is_same_v<decltype(p), std::pair<int, double>>));

    std::cout << "[TestCase] std::pair successfully deduced as std::pair<int, double>\n";
    
    // Output the pair elements
    std::cout << "[TestCase] First: " << p.first << ", Second: " << p.second << "\n";

    // Validate values
    assert(p.first == 42);
    assert(p.second == 3.14);

    std::cout << "All std::pair tests completed successfully!\n";

    return 0;
}

