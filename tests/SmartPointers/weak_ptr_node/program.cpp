#include <iostream>
#include <memory>

class Node {
public:
    std::shared_ptr<Node> child;
    std::weak_ptr<Node> parent;
};

int main() {
    auto parent = std::make_shared<Node>();
    auto child = std::make_shared<Node>();
    child->parent = parent;
    parent->child = child;

    if (auto sharedParent = child->parent.lock()) {
        std::cout << "Parent is alive" << std::endl;
    }
    else {
        std::cout << "Parent was deleted" << std::endl;
    }
}
