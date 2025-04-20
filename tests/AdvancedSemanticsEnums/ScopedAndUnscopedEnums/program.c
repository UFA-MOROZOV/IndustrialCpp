#include <iostream>
#include <magic_enum.hpp>

using namespace std;

// unscoped enum
enum Color1 {
    Red,
    Green,
    Blue
};

// scoped enum
enum class Color2 {
    Red,
    Green,
    Blue
};

int main() {    
    Color1 color1 = Red;

    if (color1 == Red)
        std::cout << "The color is red.\n";

    color1 = Blue;

    if (color1 == Blue)
        std::cout << "The color is blue.\n";

    std::cout << color1 << endl; // fine, prints integer value!
    int i = color1;      // fine, can convert...
  
    Color2 color2 = Color2::Red;

    if (color2 == Color2::Red)
        std::cout << "The color is red.\n";

    color2 = Color2::Blue;

    if (color2 == Color2::Blue)
        std::cout << "The color is blue.\n";

    // std::cout << color; // error, no matching << operator
    // int i = color;      // error: cannot convert
}
