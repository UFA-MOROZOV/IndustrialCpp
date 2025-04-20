#include <bits/stdc++.h>
using namespace std;


// Also just a little related, but important part
class A {
public:
    ~A() {
        cout << "Delete A" << endl;
    }
};
    
class B: public A{
public:
    ~B() {
        cout << "Delete B" << endl;
    }

};

void checkDestructors(){
    
    A* obj1 = new B;
    B* obj2 = new B;

    // When calling delete obj1, if the destructor in class A is not virtual,
    // only A's destructor will be called (not B's). This leads to incomplete destruction
    // of the B object, which can cause memory leaks.
    // When delete obj2 is called, the B destructor is invoked properly because the pointer
    // is of type B and the destructor is correctly inherited.

    delete obj1; // Only A's destructor is called for obj1 (potential memory leak)
    delete obj2; // Both B's and A's destructors are called for obj2 if virtual destructors are used
    // output:
    // Delete A
    // Delete B
    // Delete A
}

int main(){
    checkDestructors();
}