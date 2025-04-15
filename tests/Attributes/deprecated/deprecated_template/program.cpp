#include <iostream>

template <typename T>
[[deprecated("Use newTemplateFunction instead!")]]
void oldTemplateFunction(T input) {
    std::cout << "Old template function input: " << input << std::endl;
}

template <typename T>
void newTemplateFunction(T input) {
    std::cout << "New template function input: " << input << std::endl;
}

int main() {
    oldTemplateFunction("bla-bla-bla");
    newTemplateFunction("bla-bla-bla");
    return 0;
}