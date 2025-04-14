#include <iostream>

using namespace std;

class socket {
    int port;
public:
    socket(int port) : port(port) {}

    socket(const socket&) = delete;
    socket& operator=(const socket&) = delete;
};

int main() {
    socket sock(8888);

    socket sock2 = sock;
    return 0;
}
