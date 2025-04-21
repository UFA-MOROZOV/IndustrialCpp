#include <iostream>
#include <optional>
#include <functional>

template<typename T, typename Func>
auto transform(const std::optional<T>& opt, Func func) -> std::optional<decltype(func(*opt))> {
    if (opt) {
        return func(*opt);
    }
    return std::nullopt;
}

template<typename T, typename Fallback>
T or_else(const std::optional<T>& opt, Fallback fallback) {
    if (opt) {
        return *opt;
    }
    return fallback();
}

int main() {
    // Пример transform
    std::optional<int> opt = 5;
    auto squared = transform(opt, [](int x) { return x * x; });

    if (squared) {
        std::cout << "squared: " << *squared << "\n";  
    } else {
        std::cout << "squared is empty\n";
    }

    // Пример or_else
    std::optional<int> empty_opt;
    auto value = or_else(empty_opt, [] { return 42; });

    std::cout << "value from or_else: " << value << "\n"; 

    return 0;
}
