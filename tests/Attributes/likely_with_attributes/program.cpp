#include <iostream>

constexpr double pow(double x, int n) noexcept {
	if (n > 0) [[likely]]
		return x * pow(x, n - 1);
	else [[unlikely]]
		return 1;
}

int main() {
	double base = 2.0;
	int exp = 10;
	
	std::cout << "With attributes: " << pow(base, exp) << std::endl;

	return 0;
}

