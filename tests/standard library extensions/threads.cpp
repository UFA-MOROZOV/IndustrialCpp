// since c++ 11
#include <thread>
#include <iostream>

void sayHello() {
    std::cout << "Hello from thread!\n";
}

int main() {
    std::thread t(sayHello);
    t.join();
}
