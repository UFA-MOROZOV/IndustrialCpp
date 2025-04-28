#include <iostream>
#include <magic_enum.hpp>

using namespace std;

//Bitmask
enum class Permissions : uint8_t {
    NONE = 0,
    READ = 1 << 0,  // 00000001 in binary
    WRITE = 1 << 1, // 00000010 in binary
    EXEC = 1 << 2   // 00000100 in binary
};

// Operator for union permissions
Permissions operator|(Permissions lhs, Permissions rhs) {
    return static_cast<Permissions>(
        static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs)
    );
}

int main() {    
    //Binary bitmasks for enum constants
    Permissions p = Permissions::READ | Permissions::WRITE;
    std::cout << "Permissions value: " << static_cast<uint8_t>(p) << std::endl;
    return 0;
}
