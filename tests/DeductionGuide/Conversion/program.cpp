#include <iostream>
#include <string>

template <typename T>
class Wrapper {
public:
    T value;

    template<typename U>
    Wrapper(U* msg) : value(msg) {  // Implicit conversion from U (char*) to T (std::string)
        std::cout << "Constructor called with argument type: " << typeid(U).name() << "\n";
        std::cout << "Wrapper instantiated with T = " << typeid(T).name() << "\n";
    }
};

// Deduction guide that forces T to be std::string
template <typename T>
Wrapper(T) -> Wrapper<std::string>;  // Deduction: T is always std::string

int main() {
    const char* message = "Hello, World!";  // Type: const char*

    std::cout << "Creating Wrapper with message: " << message << "\n";

    // This will trigger the deduction guide
    Wrapper w = message;  

    std::cout << "Stored value: " << w.value << "\n";
	std::cout << "Case passed!\n";
    return 0;
}

