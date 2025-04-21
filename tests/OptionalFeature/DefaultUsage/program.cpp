#include <optional>
#include <vector>
#include <iostream>
std::optional<int> findIndex(const std::vector<int>& vec, int value) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == value) {
            return i;
        }
    }
    return std::nullopt;
 }
 
 int main() {
    auto index = findIndex({ 1, 2, 3 }, 2);
    if (index) {
        std::cout << "Found at index: " << *index << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
 }
 
 