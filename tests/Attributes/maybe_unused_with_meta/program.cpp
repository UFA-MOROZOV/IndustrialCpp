#include <iostream>

#define USE_FEATURE_X

void myFunction() {
    [[maybe_unused]] int x = 42;
#ifdef USE_FEATURE_X
    std::cout << "x integer is used: " << x << std::endl;
#endif
}

int main() {
    myFunction();
    return 0;
}