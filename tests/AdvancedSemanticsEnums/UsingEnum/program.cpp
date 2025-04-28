#include <iostream>
#include <magic_enum.hpp>

using namespace std;

enum class ComputeStat {
    OK,
    Error
};

int main() {    
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

    return 0;
}
