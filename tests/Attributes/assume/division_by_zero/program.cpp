#include <iostream>

void exampleAssume(int x) {
    [[assume(x > 0)]]; // Compilator supposes that x > 0
    // Could be optimized (division by 0 is not checked!)
    // Leads to UB if x <=0, program will perform division by 0
    // and return something or crash.
    std::cout << 1000 / x << "\n";
}

int main() {
    exampleAssume(5);  // OK, 1000
    exampleAssume(-1); // Undefined Behaviour!
    return 0;
}
