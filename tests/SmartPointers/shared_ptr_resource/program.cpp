#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource acquired" << std::endl; }
    ~Resource() { std::cout << "Resource released" << std::endl; }
};

void useResource(std::shared_ptr<Resource> res) {
    std::cout << "Using resource" << std::endl;
}

int main() {
    std::shared_ptr<Resource> res1 = std::make_shared<Resource>();
    {
        std::shared_ptr<Resource> res2 = res1;
        useResource(res2);
        std::cout << "Reference count: " << res2.use_count() << std::endl;
    }
    std::cout << "Reference count: " << res1.use_count() << std::endl;
}
