#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include <typeinfo>

template <typename T>
class Logger {
public:
    std::string timestamp;
    T message;

    // Constructor for general types
    Logger(T msg) : message(msg) {
        timestamp = getTimestamp();
        std::cout << "[TestCase] Logger instantiated with T = " << typeid(T).name() << "\n";
    }

    // Constructor for const char* (explicitly converts to std::string)
    Logger(const char* msg) : message(msg) {
        timestamp = getTimestamp();
        std::cout << "[TestCase] Logger instantiated with T = std::string (deduced from const char*)\n";
    }

    void log() const {
        std::cout << "[" << timestamp << "] " << message << "\n";
    }

private:
    static std::string getTimestamp() {
        time_t now = time(0);
        char buf[80];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
        return std::string(buf);
    }
};

// Deduction guide forces Logger<const char*> to be Logger<std::string>
Logger(const char*) -> Logger<std::string>;

int main() {
    std::cout << "Running Logger deduction guide tests...\n";

    Logger log1 = "System started";  // Deduction: Logger<std::string>
    Logger log2 = 404;               // Deduction: Logger<int>
    Logger log3 = 3.14f;             // Deduction: Logger<float>

    // Assertions to validate correct type deduction
    assert((std::is_same_v<decltype(log1), Logger<std::string>>));
    assert((std::is_same_v<decltype(log2), Logger<int>>));
    assert((std::is_same_v<decltype(log3), Logger<float>>));

    std::cout << "[TestCase] All type deduction assertions passed!\n";

    log1.log();  // [2025-03-07 12:30:15] System started
    log2.log();  // [2025-03-07 12:30:16] 404
    log3.log();  // [2025-03-07 12:30:17] 3.14

    std::cout << "All Logger tests completed successfully!\n";

    return 0;
}

