#include <iostream>
#include <numeric>
#include <vector>
#include <execution>

void test_reduce() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    int sum_seq = std::reduce(std::execution::seq, numbers.begin(), numbers.end());
    int sum_par = std::reduce(std::execution::par, numbers.begin(), numbers.end());

    std::cout << "Sequential sum: " << sum_seq << "\n";
    std::cout << "Parallel sum: " << sum_par << "\n";
}

int main() {
    test_reduce();
    return 0;
}