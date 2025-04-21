#include <iostream>


void print() {
    std::cout << std::endl;
}

template<typename T, typename... Ts>
void print(const T& first, const Ts&... rest) {
    std::cout << first << " ";
    print(rest...);
}

template<typename... Args>
class VariadicContainer {
public:
    VariadicContainer(Args... args) : data{ args... } {}

    void printContents() const {
        std::apply([](const Args&... elements) {
            print(elements...);
        }, data);
    }

private:
    std::tuple<Args...> data;
};

int main() {
    VariadicContainer<int, double, std::string> vc(42, 3.1415, "hello");
    std::cout << "Contents of VariadicContainer: ";
    vc.printContents();  // 42 3.1415 hello

    VariadicContainer<std::string, std::string, std::string> words("C++", "variadic", "templates");
    std::cout << "Words stored: ";
    words.printContents(); // C++ variadic templates

    return 0;
}
