#include <iostream>
#include <chrono>

int processNum(int n) {
    n = n % 10000000 == 0 ? 1 : 0;
    switch (n) {
        case 0:
            return 123;
        case 1:
            return 456;
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000000000; i++) {
        processNum(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time: " << elapsed.count() << " sec\n";
    return 0;
}
