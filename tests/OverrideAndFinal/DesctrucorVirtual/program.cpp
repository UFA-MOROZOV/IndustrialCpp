#include <bits/stdc++.h>
using namespace std;


// Continuation of DestructorNonvirtual.cpp

// Correct version
class A {
    public:
        virtual ~A() {
            cout << "Delete A" << endl;
        }
    };
        
    class B: public A{
    public:
        ~B() override{ // 'virtual' and 'override' are implied, hence can be omitted
            cout << "Delete B" << endl;
        }
    
    };


void checkDestructors(){
    
    A* obj1 = new B;
    B* obj2 = new B;

    
    delete obj1; 
    delete obj2; 
    // output:
    // Delete B
    // Delete A
    // Delete B
    // Delete A
}


int main(){
    checkDestructors();
}
