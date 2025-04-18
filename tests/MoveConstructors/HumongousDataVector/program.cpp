#include <algorithm>
#include <iostream>

class humongous_data_vector {
    typedef int humongous_data_t;
    humongous_data_t* data_;
    size_t size_;
    
public:
    explicit humongous_data_vector(size_t size) : data_(new humongous_data_t[size]{}), size_(size) {
        std::cout << "prime constructor.\n";
    }
    
    humongous_data_vector(humongous_data_vector&& other) noexcept
        : data_(other.data_), size_(other.size_) {
        std::cout << "move constructor.\n";
        other.data_ = nullptr;
        other.size_ = 0;
    }
    
    ~humongous_data_vector() { delete[] data_; }

    // Not allowing to copy humongous data
    humongous_data_vector(const humongous_data_vector&) = delete;
    humongous_data_vector& operator=(const humongous_data_vector&) = delete;
};

int main() {
    humongous_data_vector vec1(100);

    humongous_data_vector vec2(std::move(vec1));  // Valid resource transfer

    return 0;
}