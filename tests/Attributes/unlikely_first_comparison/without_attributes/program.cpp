#include <iostream>
#include <chrono>

int processNum(long long n) {
    if (n % 1000000000) {
        return 2;
    }
    if (n % 2 == 0) {
        return -1;
    }
    return 0;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    for (long long i = 0; i <= 1000000000; i++) {
        processNum(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time: " << elapsed.count() << " sec\n";
    return 0;
}
