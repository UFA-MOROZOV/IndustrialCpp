#include <iostream>

struct RGB {
    int r, g, b;
    void print() const {
        std::cout << "RGB(" << r << ", " << g << ", " << b << ")\n";
    }
};

RGB operator"" _red(unsigned long long val) {
    return RGB{static_cast<int>(val), 0, 0};
}

RGB operator"" _green(unsigned long long val) {
    return RGB{0, static_cast<int>(val), 0};
}

int main() {
    RGB a = 255_red;
    RGB b = 128_green;
    a.print();
    b.print();
    return 0;
}
