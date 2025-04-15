#include <iostream>

[[deprecated("Use NewEnum instead!")]]
enum OldEnum {A = 1, B = 2, C = 3};

enum NewEnum {D = 4, E = 5, F = 6};

int main() {
    OldEnum oldVal = A;
    NewEnum newVal = D;
    std::cout << oldVal << ' ' << newVal << std::endl;
    return 0;
}