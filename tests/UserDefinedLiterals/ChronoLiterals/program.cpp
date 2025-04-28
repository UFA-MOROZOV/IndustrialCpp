#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main() {
    std::cout << "Sleeping for 2 seconds...\n";
    std::this_thread::sleep_for(2s);
    std::cout << "Awake!\n";
    return 0;
}
