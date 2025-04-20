#include <iostream>
#include <memory>
#include <vector>

template<typename T>
struct EmptyAllocator {
    using value_type = T;

    T* allocate(size_t n) {
        std::cout << "Allocating " << n << " elements" << std::endl;
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, size_t n) {
        std::cout << "Deallocating " << n << " elements" << std::endl;
        ::operator delete(p);
    }
};

template<typename T, typename Allocator = EmptyAllocator<T>>
class MyContainer {
public:
    MyContainer() = default;

    void add(const T& value) {
        // some add logic
    }

private:
    std::vector <T> v;
    [[no_unique_address]] Allocator alloc;
};


int main() {
    MyContainer<int> container;
    container.add(42);
    container.add(84);

    std::cout << "Size of MyContainer: " << sizeof(MyContainer<int>) << std::endl;
    return 0;
}