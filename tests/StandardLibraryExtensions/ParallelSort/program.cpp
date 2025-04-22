#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

void test_parallel_sort() {
    std::vector<int> data = {5, 3, 1, 4, 2};
    std::sort(std::execution::par, data.begin(), data.end());

    std::cout << "Sorted data: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    test_parallel_sort();
    return 0;
}