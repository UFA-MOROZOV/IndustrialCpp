#include <iostream>

constexpr long double operator"" _cm(long double val) {
    return val / 100.0;
}

constexpr long double operator"" _m(long double val) {
    return val;
}

constexpr long double operator"" _km(long double val) {
    return val * 1000.0;
}

int main() {
    long double dist = 2.5_km + 30.0_m + 50.0_cm;
    std::cout << "Total distance in meters: " << dist << " m\n";
    return 0;
}
