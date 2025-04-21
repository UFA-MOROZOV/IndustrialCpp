#include <iostream>
#include <string_view>

void test_string_view() {
    std::string_view text = "Hello, C++";
    std::cout << "String view content: " << text << "\n";
}

int main() {
    test_string_view();
    return 0;
}