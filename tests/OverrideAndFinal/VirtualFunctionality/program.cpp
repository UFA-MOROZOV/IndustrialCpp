#include <bits/stdc++.h>
using namespace std;


class Ancestor {
public:
    void f() {
        cout << "Function f of a class Ancestor" << endl;
    };

    void g() {
        cout << "Function g of a class Ancestor" << endl;
    }

};


class Base : public Ancestor {
public:
    virtual void f() { // virtual function (overrides the non-virtual Ancestor::f)
    }; 
    virtual void g() = 0; // pure virtual function (overrides the non-virtual Ancestor::f)
    void m();
};

class Correct1 : public Base {
public:
    void f() {
        cout << "Function f of a class Correct1" << endl;
    }; // virtual because Base::f is virtual
    void g() = 0; // still a pure virtual function
};

class Correct2 : public Base {
public:
    virtual void f() {
        cout << "Function f of a class Correct2" << endl;
    }; // virtual because Base::f is virtual
    virtual void g() final{
        cout << "Function g of a class Correct2" << endl;
    }; // virtual function
};


int checkUpcasting(){ // This is a bit unrelated to specifically 'override' and 'final', but quite interesting
    Base* obj1 = new Correct2;
    Ancestor* obj2 = obj1;
    obj1->f();
    obj2->f();  // polymorphism is lost when upcasting, as the Ancestor class does not have a virtual f()
    // output:
    // Function f of a class Correct2
    // Function f of a class Ancestor
}