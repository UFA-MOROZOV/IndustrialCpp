#include <iostream>

enum Color {
    RED,
    GREEN,
    BLUE
};

int main() {
    Color myColor = RED;
    int colorValue = static_cast<int>(myColor); // Convert enum to int

    std::cout << "Enum value: " << colorValue << "\n";

    return 0;
}