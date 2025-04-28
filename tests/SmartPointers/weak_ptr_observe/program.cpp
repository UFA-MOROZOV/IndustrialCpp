#include <iostream>
#include <memory>

std::weak_ptr<int> weak;

void observe() {
    std::cout << "weak.use_count() == " << weak.use_count() << ";" << std::endl;

    if (auto shared_from_weak = weak.lock()) {
        std::cout << "*shared_from_weak == " << *shared_from_weak << std::endl;
    }
    else {
        std::cout << "weak is expired" << std::endl;
    }
}

int main() {
    {
        auto sp = std::make_shared<int>(777);
        weak = sp;
        observe();
    }
    observe();
}
