#include <iostream>

template<typename T, typename Allocator = std::allocator<T>>
class WithoutAttribute {
    Allocator alloc;
    T* data;
    size_t size;
};
template<typename T, typename Allocator = std::allocator<T>>
class WithAttribute {
    [[no_unique_address]] Allocator alloc;
    T* data;
    size_t size;
};

int main() {
    std::cout << "WithoutAttribute size " << sizeof(WithoutAttribute<int>) << std::endl;
    std::cout << "WithAttribute size " << sizeof(WithAttribute<int>) << std::endl;
    return 0;
}