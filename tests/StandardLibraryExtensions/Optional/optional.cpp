// since c++ 17

#include <optional>
#include <iostream>

int main() {
    std::optional<int> opt;
    if (!opt) std::cout << "No value yet.\n";
    opt = 100;
    std::cout << "Value is now: " << *opt << '\n';
}
