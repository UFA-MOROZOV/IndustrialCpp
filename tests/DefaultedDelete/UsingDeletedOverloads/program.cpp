#include <iostream>

using namespace std;

class pixel_coords {
    int x, y;
public:
    // prevent narrowing conversion whatsoever
    pixel_coords(double x, double y) = delete;
    pixel_coords(float x, float y) = delete;

    pixel_coords(int x, int y) : x(x), y(y) {}
};

int main() {
    pixel_coords dot1(1, 2);

    float c = 1;
    pixel_coords dot2(c, c);
    pixel_coords dot3(1., 1.2);
    return 0;
}
