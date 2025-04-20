#include <iostream>

[[deprecated("Use NewClass instead")]]
class OldClass {
public:
    OldClass() {
        std::cout << "This is old class!\n";
    }
};

class NewClass {
public:
    NewClass() {
        std::cout << "This is new class!\n";
    }
};

int main() {
    OldClass oc;
    NewClass nc;
}