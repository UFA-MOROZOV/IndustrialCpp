#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4};
    for (auto it = v.begin(); it != v.end(); ++it) {
        static_assert(std::is_same_v<decltype(it), std::vector<int>::iterator>, "Iterator type mismatch");
    }
}