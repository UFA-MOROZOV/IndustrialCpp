#include <iostream>
#include <vector>
#include <algorithm>

void exampleAssume(int n, std::vector<int>& data) {
    // Compiler assumes n is greater than 0 and
    // data is not empty and performs optimizations
    // (does not generate some instructions)
    [[assume(n > 0)]];
    [[assume(!data.empty())]];

    // Perform a calculation that could lead to UB if assumptions are violated
    int maxElement = *std::max_element(data.begin(), data.end());

    // Again, could be optimized as we can guarantee that n > 0
    int result = maxElement / n; // Division is safe if n > 0

    std::cout << "Result: " << result << "\n";
}

int main() {
    std::vector<int> values = { 1, 2, 3, 4, 5 };
    exampleAssume(5, values);  // OK, Result: 1
    exampleAssume(0, values);  // Undefined Behaviour!

    std::vector<int> emptyValues = {};
    exampleAssume(1, emptyValues); // Undefined Behaviour!

    return 0;
}
