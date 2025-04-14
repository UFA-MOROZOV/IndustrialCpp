#include <iostream>
#include <optional>
#include <type_traits>
#include <cassert>

int main() {
    std::cout << "Running std::optional deduction guide test...\n";

    // Deduction guide automatically deduces std::optional<int>
    std::optional opt = 42;  

    // Assertion to validate deduction
    assert((std::is_same_v<decltype(opt), std::optional<int>>));

    std::cout << "[TestCase] std::optional successfully deduced as std::optional<int>\n";

    if (opt) {
        std::cout << "[TestCase] Optional has a value: " << *opt << "\n";
    } else {
        std::cerr << "[Error] Optional should not be empty!\n";
        return 1;
    }

    std::cout << "All std::optional tests completed successfully!\n";
    return 0;
}

