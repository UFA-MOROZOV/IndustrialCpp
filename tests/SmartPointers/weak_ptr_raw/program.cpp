#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(10);
    std::weak_ptr<int> weakPtr = sharedPtr;

    if (auto lockedPtr = weakPtr.lock()) {
        std::cout << "Value: " << *lockedPtr << std::endl;
    } else {
        std::cout << "Object deleted" << std::endl;
    }

    sharedPtr.reset();

    if (auto lockedPtr = weakPtr.lock()) {
        std::cout << "Value: " << *lockedPtr << std::endl;
    } else {
        std::cout << "Object deleted" << std::endl;
    }
}
