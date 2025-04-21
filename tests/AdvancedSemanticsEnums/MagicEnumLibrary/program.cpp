#include <iostream>
#include <magic_enum.hpp>

using namespace std;

// unscoped enum
enum Color1 {
    Red,
    Green,
    Blue
};

int main() {    
    //using magic_enum library for work with enum 
    //Allow to iterate enum constants 
    for (auto c : magic_enum::enum_values<Color1>())  {
        //allow to convert enum to string
        std::cout << magic_enum::enum_name(c) << "\n" // Gives Red, Green, Blue
    }
    std::cout << magic_enum::enum_count<Color1>() << "\n" //Will give 3, the number of enum's contants

    return 0;
}
