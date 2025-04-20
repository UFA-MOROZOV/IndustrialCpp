#include <iostream>

class Class {
public:
    [[deprecated("Use newMethod instead!")]]
    void oldMethod() {
        std::cout << "This is old method!\n";
    }
    void newMethod() {
        std::cout << "This is new method!\n";
    }
};

int main() {
    Class cls;
    cls.oldMethod();
    cls.newMethod();
    return 0;
}