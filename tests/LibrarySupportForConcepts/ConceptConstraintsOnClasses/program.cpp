#include <iostream>
#include <vector>
#include <ranges>

// Define a concept that checks if T is a range (container-like)
template<typename T>
concept Container = std::ranges::range<T>;

template<Container C>
class ContainerPrinter {
public:
    ContainerPrinter(const C& container) : container_(container) {}
    void print() const {
        for (const auto& element : container_) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
private:
    const C& container_;
};

int main() {
    std::vector<int> vec{ 10, 20, 30, 40, 50 };
    ContainerPrinter cp(vec);
    cp.print();
    return 0;
}
