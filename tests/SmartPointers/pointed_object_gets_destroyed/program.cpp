#include <iostream>

void examplePointedObjectDestroyed() {
    int a = 10;
    std::unique_ptr<int> ptr = std::make_unique<int>(a);
}

int main() {
    examplePointedObjectDestroyed();
    
    return 0;
}
