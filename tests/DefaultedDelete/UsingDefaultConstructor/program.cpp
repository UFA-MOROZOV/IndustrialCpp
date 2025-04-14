#include <iostream>

using namespace std;

class coords {
public:
    double x = 0, y = 0;

    coords() = default;

    coords(double x, double y) : x(x), y(y) {}
};

int main() {
    coords a;

    std::cout << a.x << ' ' << a.y << '\n';
    return 0;
}
