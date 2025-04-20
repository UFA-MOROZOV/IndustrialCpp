#include <iostream>
#include <magic_enum.hpp>

using namespace std;

//underlying type
enum class ResponseStatus: uint16_t {
    SUCCESS = 200,
    NOT_FOUND = 400,
    FORBIDDEN = 403,
    ERROR = 500

};

int main() {    
    //Usage of explicit underlying types
    ResponseStatus responseStatus = ResponseStatus::OK;
    if (responseStatus == ResponseStatus::OK) {
        std::cout << "Request was successful" << std::endl;
    }

    return 0;
}
