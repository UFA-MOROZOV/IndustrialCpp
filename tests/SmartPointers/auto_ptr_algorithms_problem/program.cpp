#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::auto_ptr<int>> vec;
    vec.push_back(std::auto_ptr<int>(new int(5)));
    vec.push_back(std::auto_ptr<int>(new int(10)));

    // Sorting the vector implicitly copies auto_ptrs,
    // Causing ownership loss and undefined behavior.
    std::sort(vec.begin(), vec.end());

    for (auto it: vec) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    return 0;
}