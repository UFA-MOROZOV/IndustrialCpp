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

//underlying type
enum class ResponseStatus: uint16_t {
    SUCCESS = 200,
    NOT_FOUND = 400,
    FORBIDDEN = 403,
    ERROR = 500

};

enum class ComputeStat {
    OK,
    Error
};

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


    //Usage of explicit underlying types
    ResponseStatus responseStatus = ResponseStatus::OK;
    if (responseStatus == ResponseStatus::OK) {
        std::cout << "Request was successful" << std::endl;
    }


    //Binary bitmasks for enum constants
    Permissions p = Permissions::READ | Permissions::WRITE;
    std::cout << "Permissions value: " << static_cast<uint8_t>(p) << std::endl;
    
    //All enumerators into current scope
    ComputeStat s = ComputeStat::OK;
    switch(s){
        //This allows to address to the elements of enum outside the class specifying only those names
        using enum ComputeStat;
        case OK:
            std::cout << "ok" << "\n"; break;
        case Error:
            std::cout << "error" << "\n"; break;
        default: std::cout << "unknown..." << "\n";
    }


    //using magic_enum library for work with enum 
    //Allow to iterate enum constants 
    for (auto c : magic_enum::enum_values<Color1>())  {
        //allow to convert enum to string
        std::cout << magic_enum::enum_name(c) << "\n" // Gives Red, Green, Blue
    }
    std::cout << magic_enum::enum_count<Color1>() << "\n" //Will give 3, the number of enum's contants

    return 0;
}
