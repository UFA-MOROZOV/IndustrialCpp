#include <iostream>

void exampleChangeOwnership() {
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    //std::unique_ptr<int> incorrect = ptr;
    std::unique_ptr<int> correct = std::move(ptr);
}

int main() {
    exampleChangeOwnership();
    return 0;
}
