#include <iostream>
#include <string>


void DASH_FUNC(int test_id) {
    std::string dashes = "--------------";
    std::cout << dashes << "\n" << "Test " << test_id << "\n";
}

// ------ Test 0
namespace test_0 {

class Animal {
public:
    int age;
    std::string color;
    void live() {
        std::cout << "Is living!" << std::endl;
    }
};

class Cat : virtual public Animal {
public:
    void meow() {
        std::cout << "Meow!" << std::endl;
    }
};

class Predator : virtual public Animal {
public:
    void attack() {
        std::cout << "Attack!" << std::endl;
    }
};

class Lynx : public Cat, public Predator {
public:
    void lynx_action() {
        std::cout << "Lynx is acting!" << std::endl;
    }
};
}

// ------ Test 1
namespace test_1 {

class Base {
public:
    int init = 0;
    Base(int x) { std::cout << "Base Constructor: " << x << "\n"; init = x; }
    Base(): init(0) {}
};

class Derived1 : public virtual Base {
public:
    Derived1(int x) : Base(x) { 
        std::cout << "Derived1 Constructor\n";
        this->init *= 3;
    }
};

class Derived2 : public virtual Base {
public:
    Derived2(int x) : Base(x) { 
        std::cout << "Derived2 Constructor\n"; 
        this->init *= 4;
    }
};

class Final : public Derived1, public Derived2 {
public:
    Final(int x) : Derived1(x), Derived2(x), Base(x) {  // try to remove Base(x)
        std::cout << "Final Constructor\n"; 
    }
};
}


// ------ Test 2
namespace test_2 {

class A {
public:
    A() { std::cout << "A constructor" << std::endl; }
    virtual void method() { std::cout << "A method" << std::endl; }
};

class B : virtual private A {
public:
    B() { std::cout << "B constructor" << std::endl; }
};

class C : virtual public A {  // try to switch to private
public:
    C() { std::cout << "C constructor" << std::endl; }
};

class D : public B, public C, virtual private A { // try to switch to public
public:
    D() { std::cout << "D constructor" << std::endl; }
};
}


// ------ Test 3
namespace test_3 {

class Base {
public:
    Base(int x) { std::cout << "Base Constructor: " << x << "\n"; }
};

class Derived1 : public virtual Base {
public:
    Derived1(int x) : Base(x) { std::cout << "Derived1 Constructor\n"; }
};

class Derived2 : public virtual Base {
public:
    Derived2(int x) : Base(x) { std::cout << "Derived2 Constructor\n"; }
};

class Final : public Derived1, public Derived2 {
public:
    Final(int x) : Derived1(x), Derived2(x), Base(x) {  // try to remove Base(x)
        std::cout << "Final Constructor\n"; 
    }
};
}


// ------ Test 4
namespace test_4 {

class Base {
public:
    Base(int x) { std::cout << "Base Constructor: " << x << "\n"; }
};

class Derived1 : public virtual Base {
public:
    Derived1(int x) : Base(x) { std::cout << "Derived1 Constructor\n"; }
};

class Derived2 : public Derived1 {
public:
    Derived2(int x) : Derived1(x), Base(x)  {  // try to remove Base(x)
        std::cout << "Derived2 Constructor\n"; 
    }
};
}

// ------ Test 5
namespace test_5 {

class Base {
public:
    Base(int x) { std::cout << "Base Constructor: " << x << "\n"; }
    Base() { std::cout << "Base default constructor: " << -1 << "\n"; }
};

class Derived1 : public virtual Base {
public:
    Derived1(int x) : Base(x) { std::cout << "Derived1 Constructor\n"; }
};

class Derived2 : public Derived1 {
public:
    Derived2(int x) : Derived1(x) {  // we call Base() implicitly
        std::cout << "Derived2 Constructor\n"; 
    }
};
}


int main() {
    DASH_FUNC(0);
    test_0::Cat cat;
    cat.meow();

    test_0::Predator predator;
    predator.attack();

    test_0::Lynx lynx;
    lynx.lynx_action();
    lynx.age = 5;
    std::cout << lynx.age << std::endl;

    DASH_FUNC(1);
    test_1::Final obj1(10);
    std::cout << obj1.init << std::endl;

    DASH_FUNC(2);
    test_2::D d;
    d.method();

    DASH_FUNC(3);
    test_3::Final obj3(10);

    DASH_FUNC(4);
    test_4::Derived2 obj4(10);

    DASH_FUNC(5);
    test_5::Derived2 obj5(10);

    return 0;
}