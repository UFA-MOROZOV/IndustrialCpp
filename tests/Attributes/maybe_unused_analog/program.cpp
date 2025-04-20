// What developers were doing before [[maybe_unused]] was released.
#include <iostream>

void myFunction(int param) {
    (void)param;
}

#define UNUSED(x) (void)(x)
void myFunction1(int param) {
    UNUSED(param);
}

int main() {
    myFunction(123);
    myFunction1(456);
    return 0;
}