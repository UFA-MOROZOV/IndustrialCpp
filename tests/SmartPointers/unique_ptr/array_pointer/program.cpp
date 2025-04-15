#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int[]> arr(new int[5]{1, 2, 3, 4, 5});
    return 0;
}
