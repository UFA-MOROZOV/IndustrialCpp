#include <iostream>
#include <string_view>

struct LoggerConfig {
    // Constructor needs to be constexpr to be used for constinit
    constexpr LoggerConfig(const int lev, const char* path)
        : logLevel(lev), logPath(path) {}

    int logLevel;
    std::string_view logPath;
};

// Global variable initialized at compile-time
constinit LoggerConfig loggerConfig{3, "/var/log/myapp.log"};

// Error example: Cannot initialize with non-constant variable
// int x = 3;
// constinit LoggerConfig errorConfig{x, "/var/log/myapp.log"};


int main() {
    // Access the constinit variable
    std::cout << "Log Level: " << loggerConfig.logLevel << std::endl;
    std::cout << "Log Path: " << loggerConfig.logPath << std::endl;

    // Modify the constinit variable at runtime
    loggerConfig.logLevel = 4; // This is allowed
    std::cout << "Updated Log Level: " << loggerConfig.logLevel << std::endl;

    return 0;
}