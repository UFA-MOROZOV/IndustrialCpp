// since c++ 17

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::path path = fs::current_path();
    std::cout << "Current path: " << path << '\n';
}

