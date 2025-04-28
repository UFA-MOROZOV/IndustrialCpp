#include "VirtualFunctionality.cpp"

class OverrideNotSpecified : public Correct2 {
public:
    //This is the demonstration of what are possible mistakes programmer
    // might do if not specify override keyword

    // suppose you intended to override f()

    //initially intended
    void f(){
        // no error 
        cout << "Default f" << endl;
    }

    // but you forgot the initial type modifier
    void f() const{
        // no error
        cout << "Const f" << endl;
    }

    // or the signature
    void f(int x) { 
        // no error
        cout << "f with parameter" << endl;
    };

    // the compiler won't tell you anything, and you will not overrdie the function
    // but create a new ones with different signatures

    // // however, changing the return value is still a safepoint
    // int f()  { // if uncommented shows error because of a conflict with void f() of OverrideNotSpecified
    //     // return type is not identical to nor covariant with return type "void" of overridden virtual function "Base::f
    // }

   

    // still you will get the notification if you try to override the final method
    // void g() { 
    //     // error: cannot override 'final' function "KeywordsCombinations::g"
    // }

    // but not if you change the signature
    void g(int x) {
        
    }
    
    // However, if you add the 'override' specifier, the compiler will check the vtable of the base class
    // to ensure that the function you're trying to override actually exists in the base class 
    // and matches the correct signature. If no matching virtual function is found, the compiler
    // will generate an error.


    void m() { // intended to override m() from Ancestor
        // no error
    };
};


int main(){
    OverrideNotSpecified* ons = new OverrideNotSpecified;
    ons->f();
    ons->f(1);
    const OverrideNotSpecified* ons2 = new OverrideNotSpecified;
    ons2->f();
}